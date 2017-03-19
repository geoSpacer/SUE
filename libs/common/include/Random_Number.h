#ifndef COMMON_LIB__RANDOM_NUMBER_H
#define COMMON_LIB__RANDOM_NUMBER_H

//-----------------------------------------------------------------------------

//  Class:  Random::Number
//
//  This abstract class represents a pseudo-random number generator that
//  yields a sequence of random numbers.

namespace Random
{
    //-------------------------------------------------------------------------

    class Number
    {
	public:
	    //------------
	    //	Operations

	    virtual
	    double next() = 0;
		//  Generate the next number in the sequence.
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
