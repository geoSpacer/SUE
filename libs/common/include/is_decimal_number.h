#ifndef COMMON_LIB__IS_DECIMAL_NUMBER_H
#define COMMON_LIB__IS_DECIMAL_NUMBER_H

//-----------------------------------------------------------------------------

#include <string>

//-----------------------------------------------------------------------------

bool is_decimal_number(const std::string & str);
    //	Return "true" if the string is a properly formatted decimal number:
    //
    //	    sign digit ... [ "." [ digit ... ] ] [ exponent ]
    //	    sign "." digit ... [ exponent ]
    //
    //	where
    //
    //	    sign = [ "+" | "-" ]
    //	    exponent = ( "e" | "E" ) sign digit ...
    //
    //	This function is typically used to see if the conversion of a string
    //	to an "float" (the "str_to_float" function) failed because the number
    //	was too large to store in an "float".

//-----------------------------------------------------------------------------

#endif
