#ifndef EMROTOR_HPP_
#define EMROTOR_HPP_

#include "EMEncoder.hpp"

#define SHIFTED_ORD(c) ((ORD(c) + offset) % ENCODABLE_CHARS)
#define SHIFTED_CHR(i) CHR((i - offset + ENCODABLE_CHARS) % ENCODABLE_CHARS)

class EMRotor:public EMEncoder
{
    private:
        int offset;
        int reverseCharsMap[ENCODABLE_CHARS];
    public:
        // Initialise charsMap and reverseCharsMap
        // according to the given configuration.
        EMRotor(string config);

        // EMRotor overrides the default encode method
        // of EMEncoder to take into account the offset.
        void encode (char& c);

        // Encode a character by performing a lookup in
        // the reverseCharsMap table.
        void reverse_encode(char& c);

        // Increment the offset of this rotor and return
        // true if the next rotor should rotate as well.
        bool turn();
};

#endif
