#ifndef COMMON_LIB__ASSERT_THAT_H
#define COMMON_LIB__ASSERT_THAT_H

//-----------------------------------------------------------------------------

#include "Assertion_Error.h"

//-----------------------------------------------------------------------------

//  Macro:  ASSERT_THAT
//
//  This macro is used to test assertions.  If the condition is not true, then
//  the macro throws an Assertion_Error exception.  Since the condition is
//  used to print a message for an Assertion_Error, try to use meaningful
//  identifier names in the condition.  For example,
//
//	ASSERT_THAT((0 <= row) && (row < maxRows))


//  Macro:  DISABLE_ASSERT
//
//  If this macro is defined, assertion testing is disabled.

#ifdef DISABLE_ASSERT
    #define ASSERT_THAT(condition)
#else
    #define ASSERT_THAT(condition) \
    { \
	if (! (condition)) \
	    throw Assertion_Error( #condition , __FILE__, __LINE__ ); \
    }
#endif

//-----------------------------------------------------------------------------

#endif
