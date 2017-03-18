#ifndef COMMON_LIB__RANDOM_UNIFORM_H
#define COMMON_LIB__RANDOM_UNIFORM_H

//-----------------------------------------------------------------------------

#include "Random_Number.h"
#include "MTRand.h"

//-----------------------------------------------------------------------------

//  Class:  Random::Uniform
//
//  This class represents a pseudo-random number generator that yields a
//  sequence of random numbers between [0.0, 1.0] with a uniform distribution.
//
//  The class is based on the Mersenne Twister pseudo-random number generator
//  as implemented by Martin Hinsch and Shawn Cokus (i.e., the "MTRand" class).

namespace Random
{
    //-------------------------------------------------------------------------

    class Uniform
	: public Number
    {
	public:
	    //------------
	    //	Operations

	    Uniform(unsigned int seed);
		//  Construct a uniform random number generator using the
		//  initial seed value.  {seed} must be odd.

	    double next();
		//  Generate the next number in the sequence.

	//---------------------------------------------------------------------

	private:
	    MTRand MT_random_num_gen_;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
