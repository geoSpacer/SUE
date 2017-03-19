#ifndef COMMON_LIB__INPUT_VAR_STR_H
#define COMMON_LIB__INPUT_VAR_STR_H

//-----------------------------------------------------------------------------

#include <string>

#include "Input_Var.h"
#include "Input_Value_Str.h"

//-----------------------------------------------------------------------------

//  Class:  Input_Var::Str
//
//  This class represents a string input variable.

namespace Input_Var
{
    //-------------------------------------------------------------------------

    class Str
	: public Input::Var<std::string>,
	  public Input_Value::Str
    {
	public:
	    Str(const std::string & name);
		//  Construct a string input variable with the given name.
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
