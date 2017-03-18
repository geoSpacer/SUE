#ifndef STR_TO_INT_H
#define STR_TO_INT_H

//-----------------------------------------------------------------------------

#include <string>

#include "Str_To_Value.h"

//-----------------------------------------------------------------------------

bool str_to_int(const std::string & str,
		int &		    value);
    //	Converts a string into an integer value.  The format of a valid
    //	integer is:
    //
    //	    ( "+" | "-" ) digit ...
    //
    //	Return value:
    //	    true    The string has a valid integer, and its value was assigned
    //		    to the "value" parameter.
    //	
    //	    false   The string has an invalid format.

//-----------------------------------------------------------------------------

//  Set the above function as the default conversion function for the
//  "int" type.

inline
Str_To_Value<int>::Func_Ptr Str_To_Value<int>::default_func()
{
    return str_to_int;
}

//-----------------------------------------------------------------------------

#endif
