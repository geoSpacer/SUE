#ifndef COMMON_LIB__INPUT_VAR_WITH_LIST_H
#define COMMON_LIB__INPUT_VAR_WITH_LIST_H

//-----------------------------------------------------------------------------

#include <vector>

//-----------------------------------------------------------------------------

//  Class template:  Input::Var_With_List<class Value_Type>
//
//  Template arguments:
//	Value_Type = the input variable's type
//
//  This abstract class represents an input variable, which has local storage
//  for a list of input values of the type {Value_Type}.

namespace Input
{
    //-------------------------------------------------------------------------

    template<class Value_Type>
    class Var_With_List
    {
	public :
	    //------------
	    //  Operations

	    Var_With_List();
		//  Construct an input variable.  It's initial value is the
		//  default value for type {Value_Type}.

	    //------------
	    //  Attributes

	    const std::vector<Value_Type> & values() const;
		//  The variable's list of values.

	protected :
	    //------------
	    //  Attributes

	    std::vector<Value_Type> & location();
		//  The location where the variable's value is.

	private :
	    std::vector<Value_Type> values_;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "Input_Var_With_List.inl"

//-----------------------------------------------------------------------------

#endif
