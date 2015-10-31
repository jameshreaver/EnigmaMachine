#include "EMPlugboard.hpp"

EMPlugboard::EMPlugboard(string config)
{
    for (int i = 0; i < ENCODABLE_CHARS; i++) {
        charsMap[i] = i;
    }

    istringstream stream(config);
    int i, j;
    while (stream >> i && stream >> j) {
        if (VALID_ORD(i) && VALID_ORD(j)) {
            charsMap[i] = j;
            charsMap[j] = i;
        } else {
            throw invalid_argument(PLUGBOARD_ERR);
        }
    }
}
