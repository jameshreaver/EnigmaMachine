#include <iostream>
#include <fstream>
#include <stdexcept>
#include "EnigmaMachine.hpp"

#define FILE_ERR "Error opening file: "
#define PLUG_ERR "Missing plugboard configuration."

// Read the message to be encrypted
// from the standard input.
string readInput();

// Return a string containing the contents
// of a configuration file.
string readConfig(string filename);

// Return a string containing the plugboard
// configuration.
string getPlugboardConfig(int argc, char **argv);

// Return a list of strings containing the
// rotor configurations.
list<string> getRotorConfigs(int argc, char **argv);


int main(int argc, char **argv)
{
    try {
        string plugboardConfig = getPlugboardConfig(argc, argv);
        list<string> rotorConfigs = getRotorConfigs(argc, argv);
        EnigmaMachine machine(plugboardConfig, rotorConfigs);

        string message = readInput();
        machine.encrypt(message);
        cout << message << endl;

    } catch (invalid_argument& e) {
        cerr << e.what() << endl;
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}

string readInput()
{
    string input, line;
    while (!cin.eof()) {
        cin >> line;
        input.append(line);
        cin >> ws;
    }
    return input;
}

string readConfig(string filename)
{
    ifstream file(filename.c_str());
    if (file.good()) {
        string line;
        getline(file, line);
        file.close();
        return line;
    } else {
        throw invalid_argument(FILE_ERR + filename);
    }
}

string getPlugboardConfig(int argc, char **argv)
{
    if (argc == 1) {
        throw invalid_argument(PLUG_ERR);
    }
    return readConfig(argv[argc-1]);
}

list<string> getRotorConfigs(int argc, char **argv)
{
    list<string> rotorConfigs;
    if (argc > 2) {
        for (int i = 1; i < argc-1; i++) {
            rotorConfigs.push_back(readConfig(argv[i]));
        }
    }
    return rotorConfigs;
}
