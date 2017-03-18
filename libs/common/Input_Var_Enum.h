#ifndef COMMON_LIB__INPUT_VAR_ENUM_H
#define COMMON_LIB__INPUT_VAR_ENUM_H

//-----------------------------------------------------------------------------

#include "Input_Var.h"
#include "Input_Value_Enum.h"

//-----------------------------------------------------------------------------

//  Class:  Input_Var::Enum<class Enum_Type>
//
//  Template parameters:
//	Enum_Type = an enumerated type (e.g., Month)
//
//  This represents an input variable for values of an enumerated type
//  {Enum_Type}.

namespace Input_Var
{
    //-------------------------------------------------------------------------

    template<class Enum_Type,
	     class Dummy = Input_Value::Enum<Enum_Type> >
		//  This 2nd class is a workaround; for details, look at the
		//  header for the Input_Var::Num template class.
    class Enum
	: public Input::Var<Enum_Type>,
	  public Input_Value::Enum<Enum_Type>
    {
	public:
	    //------------
	    //  Operations

	    Enum(const std::string &		   name,
		 const std::string &		   description,
		 Str_To_Value<Enum_Type>::Func_Ptr function
						    = Str_To_Value<Enum_Type>::
						      default_func());
		//  Construct an enumerated input variable with the given name
		//  and description (= a brief phrase describing what sort of
		//  input values that the enumerated type expects, e.g., "a
		//  month abbreviation (3-letter)").  The {function} is used
		//  to convert string values into values of the enumerated
		//  type.
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "Input_Var_Enum.inl"

//-----------------------------------------------------------------------------

#endif
