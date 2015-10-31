#include "EMEncoder.hpp"

void EMEncoder::encode(char& c)
{
    c = CHR(charsMap[ORD(c)]);
}
