#ifndef COMMON_LIB__INPUT_VALUE_FLOAT_H
#define COMMON_LIB__INPUT_VALUE_FLOAT_H

//-----------------------------------------------------------------------------

#include "Input_Value_Num.h"
#include "is_decimal_number.h"
#include "str_to_float.h"	//  for Str_To_Value<float>::default_func()

//-----------------------------------------------------------------------------

namespace Input_Value
{
    //-------------------------------------------------------------------------

    typedef Num<float> Float;

    //-------------------------------------------------------------------------

    inline
    const char * Float::type_description()
    {
	return "a number";
    }

    //-------------------------------------------------------------------------

    inline
    bool Float::is_valid_number(const std::string & str)
    {
	return is_decimal_number(str);
    }

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
