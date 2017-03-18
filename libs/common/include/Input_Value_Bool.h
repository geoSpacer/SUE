#ifndef COMMON_LIB__INPUT_VALUE_BOOL_H
#define COMMON_LIB__INPUT_VALUE_BOOL_H

//-----------------------------------------------------------------------------

#include "Input_Value_Enum.h"
#include "str_to_bool.h"	//  for Str_To_Value<bool>::default_function()

//-----------------------------------------------------------------------------

//  Class:  Input_Value::Bool
//
//  This class represents a boolean input value.

namespace Input_Value
{
    //-------------------------------------------------------------------------

    typedef Enum<bool> Bool;

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
