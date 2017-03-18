#ifndef COMMON_LIB__RANDOM_EXPONENTIAL_H
#define COMMON_LIB__RANDOM_EXPONENTIAL_H

//-----------------------------------------------------------------------------

#include "Random_Number.h"
#include "Random_Uniform.h"

//-----------------------------------------------------------------------------

//  Class:  Random::Exponential
//
//  This class represents a pseudo-random number generator that yields a
//  sequence of random numbers > 0 with a standard exponential distribution.
//
//  This type of distribution is sometimes called a negative exponential
//  distribution.

namespace Random
{
    //-------------------------------------------------------------------------

    class Exponential
	: public Number
    {
	public:
	    //------------
	    //	Operations

	    Exponential(unsigned int seed);
		//  Construct an exponential random number generator using the
		//  initial seed value.  {seed} must be odd.

	    Exponential(Uniform & uniform_rand_num_gen);
		//  Construct an exponential random number generator which
		//  will use the given uniform random number generator.

	    double next();
		//  Generate the next number in the sequence.

	    ~Exponential();
		//  Destroy the object.

	//---------------------------------------------------------------------

	private:
	    Uniform * uniform_random_num_gen_;
	    bool      local_generator_;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
