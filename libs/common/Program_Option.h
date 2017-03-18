#ifndef COMMON_LIB__PROGRAM_OPTION_H
#define COMMON_LIB__PROGRAM_OPTION_H

//-----------------------------------------------------------------------------

#include <string>

#include "Required_or_Optional.h"

//-----------------------------------------------------------------------------

//  Enum:  Value_Status
//
//  This enumerated type indicates whether a program option has no value,
//  requires a value, or may have a value.

enum Value_Status
{
    No_Value,
    Value_Required,
    Value_Optional
};

//-----------------------------------------------------------------------------

//  Struct:  Program_Option
//
//  This structure represents a single program option.

struct Program_Option
{
    //------------
    //	Attributes

    std::string		 name;
    unsigned int	 id;
    Required_or_Optional reqd_or_opt;
    Value_Status	 value_status;

    //------------
    //	Operations
    Program_Option(const std::string &  name,
		   unsigned int	        id,
		   Required_or_Optional reqd_or_opt,
		   Value_Status		value_status);
};

//-----------------------------------------------------------------------------

#endif
