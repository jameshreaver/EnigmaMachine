#ifndef EMPLUGBOARD_HPP_
#define EMPLUGBOARD_HPP_

#include "EMEncoder.hpp"

class EMPlugboard:public EMEncoder
{
    public:
        // Initialise charsMap and perform the swaps
        // according to the given configuration.
        EMPlugboard(string config);
};


#endif
