#ifndef ENIGMAMACHINE_HPP_
#define ENIGMAMACHINE_HPP_

#include <list>
#include "EMPlugboard.hpp"
#include "EMRotor.hpp"
#include "EMReflector.hpp"

class EnigmaMachine
{
    private:
        EMPlugboard plugboard;
        list<EMRotor> rotors;
        EMReflector reflector;

        // Perform the encryption process on the given char.
        // The encryption is performed in-place.
        void encryptChar(char& c);

    public:
        // Construct an Enigma Machine from the given
        // plugboard and rotor configurations.
        EnigmaMachine(string plugboardConfig,
            list<string> rotorsConfigs);

        // Perform the encryption process on the given string.
        // The encryption is performed in-place.
        void encrypt(string& message);

        // Perform the rotation of the machine rotors.
        void rotate();
};

#endif
