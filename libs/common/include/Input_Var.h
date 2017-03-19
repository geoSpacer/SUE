#ifndef COMMON_LIB__INPUT_VAR_H
#define COMMON_LIB__INPUT_VAR_H

//-----------------------------------------------------------------------------

//  Class template:  Input::Var<class Value_Type>
//
//  Template arguments:
//	Value_Type = the input variable's type
//
//  This abstract class represents an input variable, which is an Input::Value
//  with associated local storage for the value.

namespace Input
{
    //-------------------------------------------------------------------------

    template<class Value_Type>
    class Var
    {
	public :
	    //------------
	    //  Operations

	    Var();
		//  Construct an input variable.  It's initial value is the
		//  default value for type {Value_Type}.

	    //------------
	    //  Attributes

	    Value_Type value() const;
		//	The variable's value.

	protected :
	    //------------
	    //  Attributes

	    Value_Type & location();
		//  The location where the variable's value is.

	private :
	    Value_Type value_;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "Input_Var.inl"

//-----------------------------------------------------------------------------

#endif
