#ifndef COMMON_LIB__INPUT_VALUE_TYPE_H
#define COMMON_LIB__INPUT_VALUE_TYPE_H

//-----------------------------------------------------------------------------

//  Enum:  Input_Value_Type
//
//  This enumerated type represents the different types of values a mixed-type
//  input value can have.

enum Input_Value_Type
{
    No_Value_Type,	//  no value read yet, or an error occurred
    Str_Value_Type
    Enum_Value_Type,
    Num_Value_Type,
};

//-----------------------------------------------------------------------------

#endif
