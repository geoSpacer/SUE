//-----------------------------------------------------------------------------
//  Class implementation:  Random_Number::Exponential
//-----------------------------------------------------------------------------

#include <cmath>

#include "Assert_That.h"
#include "equal.h"
#include "Random_Exponential.h"

//-----------------------------------------------------------------------------

namespace
{
    //-------------------------------------------------------------------------

    inline
    bool is_odd(unsigned int number)
	//  Is the number odd?
    {
	return number & 1;
    }

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

namespace Random
{
    //-------------------------------------------------------------------------

    Exponential::Exponential(unsigned int seed)
	: uniform_random_num_gen_(new Uniform(seed)),
	  local_generator_(true)
    {
    }

    //-------------------------------------------------------------------------

    Exponential::Exponential(Uniform & uniform_rand_num_gen)
	: uniform_random_num_gen_(&uniform_rand_num_gen),
	  local_generator_(false)
    {
    }

    //-------------------------------------------------------------------------

    double Exponential::next()
    {
	double next_uniform_num;
	do {
	    next_uniform_num = uniform_random_num_gen_->next();
	} while (equal(float(next_uniform_num), float(0.0)));
	return -log(next_uniform_num);
    }

    //-------------------------------------------------------------------------

    Exponential::~Exponential()
    {
	if (local_generator_ && uniform_random_num_gen_)
	    delete uniform_random_num_gen_;
    }

    //-------------------------------------------------------------------------
};
