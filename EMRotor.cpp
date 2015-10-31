#include "EMRotor.hpp"

EMRotor::EMRotor(string config)
{
    offset = 0;

    istringstream stream(config);
    int number, i = 0;
    while(stream >> number) {
        if (VALID_ORD(number)) {
            reverseCharsMap[number] = i;
            charsMap[i++] = number;
        } else {
            throw invalid_argument(ROTOR_ERR);
        }
    }
}

void EMRotor::encode(char& c)
{
    c = SHIFTED_CHR(charsMap[SHIFTED_ORD(c)]);
}

void EMRotor::reverse_encode(char& c)
{
    c = SHIFTED_CHR(reverseCharsMap[SHIFTED_ORD(c)]);
}

bool EMRotor::turn()
{
    offset = (offset + 1) % ENCODABLE_CHARS;
    return (!offset);
}
