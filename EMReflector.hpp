#ifndef EMREFLECTOR_HPP_
#define EMREFLECTOR_HPP_

#include "EMEncoder.hpp"

class EMReflector:public EMEncoder
{
    public:
        // Initialise charsMap according to the encrypting
        // function for the reflector.
        EMReflector();
};

#endif
