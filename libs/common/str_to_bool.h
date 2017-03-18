#ifndef STR_TO_BOOL_H
#define STR_TO_BOOL_H

//-----------------------------------------------------------------------------

#include <string>

#include "Str_To_Value.h"

//-----------------------------------------------------------------------------

bool str_to_bool(const std::string & str,
		 bool &		     value);
    //	Converts a string into a boolean value.  Acceptable strings are:
    //
    //	    "yes" "y"	   -> true
    //	    "no"  "n" "-"  -> false
    //
    //	Case is ignored, so any variant of the strings above with uppercase
    //	letters is also acceptable.
    //
    //	Return value:
    //	    true    The string is a valid boolean string, and its corresponding
    //		    value was assigned to the "value" parameter.
    //	
    //	    false   The string has an invalid format.

//-----------------------------------------------------------------------------

//  Set the above function as the default conversion function for the
//  "bool" type.

inline
Str_To_Value<bool>::Func_Ptr Str_To_Value<bool>::default_func()
{
    return str_to_bool;
}

//-----------------------------------------------------------------------------

#endif
