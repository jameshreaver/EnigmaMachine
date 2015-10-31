#include "EnigmaMachine.hpp"

EnigmaMachine::EnigmaMachine(string plugboardConfig,
    list<string> rotorConfigs):plugboard(plugboardConfig)
{
    list<string>::iterator rotorConfig;
    for (rotorConfig  = rotorConfigs.begin();
         rotorConfig != rotorConfigs.end();
         rotorConfig++) {
       EMRotor rotor(*rotorConfig);
       rotors.push_back(rotor);
    }
}

void EnigmaMachine::encrypt(string& message)
{
    for(int i = 0; i < message.length(); i++) {
        char& c = message[i];
        if (VALID_CHR(c)) {
            encryptChar(c);
        } else {
            throw invalid_argument(INPUT_ERR);
        }
    }
}

void EnigmaMachine::encryptChar(char& c)
{
    plugboard.encode(c);

    list<EMRotor>::iterator rotor;
    for (rotor  = rotors.begin();
         rotor != rotors.end();
         rotor++) {
        rotor->encode(c);
    }

    reflector.encode(c);

    list<EMRotor>::reverse_iterator rrotor;
    for (rrotor  = rotors.rbegin();
         rrotor != rotors.rend();
         rrotor++) {
        rrotor->reverse_encode(c);
    }

    plugboard.encode(c);

    rotate();
}

void EnigmaMachine::rotate()
{
    bool shouldRotate = true;
    bool nextShouldRotate = false;

    list<EMRotor>::iterator rotor;
    for (rotor  = rotors.begin();
         rotor != rotors.end();
         rotor++) {
        if (nextShouldRotate) {
            nextShouldRotate = rotor->turn();
        }
        if (shouldRotate) {
            nextShouldRotate = rotor->turn();
            shouldRotate = false;
        }
    }

}
