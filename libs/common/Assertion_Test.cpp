#include <iostream>

#include "Assertion_Test.h"
#include "Assertion_Error.h"

//-----------------------------------------------------------------------------

void Assertion_Test::no_exception_thrown()
{
    std::cout << "  ERROR:  No exception thrown.\n";
}

//-----------------------------------------------------------------------------

void Assertion_Test::caught_Assertion_Error(const Assertion_Error & e)
{
    std::cout << "  Assertion_Error exception caught.\n"
		 "  Condition that failed:  " << e.condition() << "\n";
}

//-----------------------------------------------------------------------------

void Assertion_Test::caught_other_exception()
{
    std::cout << "  ERROR:  An exception other than Assertion_Error was"
								" thrown.\n";
}
