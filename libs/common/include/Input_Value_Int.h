#ifndef COMMON_LIB__INPUT_VALUE_INT_H
#define COMMON_LIB__INPUT_VALUE_INT_H

//-----------------------------------------------------------------------------

#include "Input_Value_Num.h"
#include "is_integer.h"
#include "str_to_int.h"		//  for Str_To_Value<int>::default_func()

//-----------------------------------------------------------------------------

namespace Input_Value
{
    //-------------------------------------------------------------------------

    typedef Num<int> Int;

    //-------------------------------------------------------------------------

    inline
    const char * Int::type_description()
    {
	return "an integer";
    }

    //-------------------------------------------------------------------------

    inline
    bool Int::is_valid_number(const std::string & str)
    {
	return is_integer(str);
    }

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
