#ifndef COMMON_LIB__IS_INTEGER_H
#define COMMON_LIB__IS_INTEGER_H

//-----------------------------------------------------------------------------

#include <string>

//-----------------------------------------------------------------------------

bool is_integer(const std::string & str);
    //	Return "true" if the string is a properly formatted integer:
    //
    //	    [ "+" | "-" ] digit ...
    //
    //	This function is typically used to see if the conversion of a string
    //	to an "int" (the "str_to_int" function) failed because the integer
    //	was too large to store in an "int".

//-----------------------------------------------------------------------------

#endif
