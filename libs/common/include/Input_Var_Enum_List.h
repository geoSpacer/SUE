#ifndef COMMON_LIB__INPUT_VAR_ENUM_LIST_H
#define COMMON_LIB__INPUT_VAR_ENUM_LIST_H

//-----------------------------------------------------------------------------

#include <vector>

#include "Input_Var_With_List.h"
#include "Input_Value_Enum_List.h"

//-----------------------------------------------------------------------------

//  Class:  Input_Var::Enum_List<class Enum_Type>
//
//  Template parameters:
//	Enum_Type = an enumerated type (e.g., Month)
//
//  This represents an input variable for a list of enumerated values of an
//  enumerated type {Enum_Type}.

namespace Input_Var
{
    //-------------------------------------------------------------------------

    template<class Enum_Type,
	     class Dummy = Input_Value::Enum_List<Enum_Type> >
		//  This 2nd class is a workaround; for details, look at the
		//  header for the Input_Var::Num template class.
    class Enum_List
	: public Input::Var_With_List<Enum_Type>,
	  public Input_Value::Enum_List<Enum_Type>
    {
	public:
	    //------------
	    //  Operations

	    Enum_List(const std::string &		name,
		      const std::string &		description,
		      Str_To_Value<Enum_Type>::Func_Ptr function =
							Str_To_Value<Enum_Type>
							::default_func());
		//  Construct an input variable for a list of enumerated
		//  values, with the given name and description (= a brief
		//  phrase describing what sort of input values that the
		//  enumerated type expects, e.g., "a month abbreviation
		//  (3-letter)").  The {function} is used to convert words
		//  into values of the enumerated type.
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "Input_Var_Enum_List.inl"

//-----------------------------------------------------------------------------

#endif
