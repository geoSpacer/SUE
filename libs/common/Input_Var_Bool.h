#ifndef COMMON_LIB__INPUT_VAR_BOOL_H
#define COMMON_LIB__INPUT_VAR_BOOL_H

//-----------------------------------------------------------------------------

#include "Input_Var_Enum.h"
#include "str_to_bool.h"	//  for Str_To_Value<bool>::default_function()

//-----------------------------------------------------------------------------

//  Class:  Input_Var::Bool
//
//  This class represents an input variable that has a boolean value.

namespace Input_Var
{
    //-------------------------------------------------------------------------

    typedef Enum<bool> Bool;

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
