#ifndef EMENCODER_HPP_
#define EMENCODER_HPP_

#include <sstream>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

using namespace std;

#define CHR(i) (i + 'A')
#define ORD(c) (c - 'A')
#define VALID_CHR(c) (c >= 'A' && c <= 'Z')
#define VALID_ORD(i) (i >= 0 && i <= ENCODABLE_CHARS)

#define PLUGBOARD_ERR "Invalid plugboard configuration."
#define ROTOR_ERR "Invalid value in rotor configuration."
#define INPUT_ERR "Invalid input character."


const int ENCODABLE_CHARS = 26;

class EMEncoder
{
    protected:
        int charsMap[ENCODABLE_CHARS];
    public:
        // In-place encode the given character.
        // Pre: the given character is valid.
        void encode(char& c);
};

#endif
