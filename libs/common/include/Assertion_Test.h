#ifndef COMMON_LIB__ASSERTION_TEST_H
#define COMMON_LIB__ASSERTION_TEST_H

//-----------------------------------------------------------------------------

#include "Assertion_Error.h"

//-----------------------------------------------------------------------------

//  Functions used by the macro below to print certain messages to standard
//  output.

namespace Assertion_Test
{
    void no_exception_thrown();
    void caught_Assertion_Error(const Assertion_Error & e);
    void caught_other_exception();
};

//-----------------------------------------------------------------------------

//  Macro:  ASSERTION_TEST
//
//  This macro is used to test assertions.  The first argument is a string
//  describing the test.  The 2nd argument is the actual C++ statement that
//  should throw an Assertion_Error exception.

#define ASSERTION_TEST(description, statement)			    \
    try {							    \
	std::cout << "Assertion test:  " << description << "\n";    \
	statement;						    \
	Assertion_Test::no_exception_thrown();			    \
    }								    \
    catch (Assertion_Error & e)					    \
    {								    \
	Assertion_Test::caught_Assertion_Error(e);		    \
    }								    \
    catch (...)							    \
    {								    \
	Assertion_Test::caught_other_exception();		    \
    }

//-----------------------------------------------------------------------------

#endif
