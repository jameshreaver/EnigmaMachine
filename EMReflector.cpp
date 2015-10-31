#include "EMReflector.hpp"

EMReflector::EMReflector()
{
    for (int i = 0; i < ENCODABLE_CHARS; i++) {
        charsMap[i] = (i + ENCODABLE_CHARS/2) % ENCODABLE_CHARS;
    }
}
