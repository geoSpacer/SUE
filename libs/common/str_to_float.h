#ifndef STR_TO_FLOAT_H
#define STR_TO_FLOAT_H

//-----------------------------------------------------------------------------

#include <string>

#include "Str_To_Value.h"

//-----------------------------------------------------------------------------

bool str_to_float(const std::string & str,
		  float &	      value);
    //	Converts a string into a float value.  The format of a valid float:
    //
    //	    [ sign ] integer [ "." [integer] ] [ exponent ]
    //	    [ sign ] "." integer [ exponent ]
    //
    //	where
    //
    //	    sign := "+" | "-"
    //	    integer := digit ...
    //	    exponent := ( "e" | "E" ) [ sign ] integer
    //
    //	Return value:
    //	    true    The string has a valid float, and its value was assigned
    //		    to the "value" parameter.
    //	
    //	    false   The string has an invalid format.

//-----------------------------------------------------------------------------

//  Set the above function as the default conversion function for the
//  "float" type.

inline
Str_To_Value<float>::Func_Ptr Str_To_Value<float>::default_func()
{
    return str_to_float;
}

//-----------------------------------------------------------------------------

#endif
