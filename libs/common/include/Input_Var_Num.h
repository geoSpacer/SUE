#ifndef COMMON_LIB__INPUT_VAR_NUM_H
#define COMMON_LIB__INPUT_VAR_NUM_H

//-----------------------------------------------------------------------------

#include "Input_Var.h"
#include "Input_Value_Num.h"

//-----------------------------------------------------------------------------

//  Class:  Input_Var::Num<class Num_Type>
//
//  Template parameter:
//	Num_Type = a numeric type (e.g., int, float)
//
//  This class represents an input variable for numeric values of the type
//  {Num_Type}.

namespace Input_Var
{
    //-------------------------------------------------------------------------

    template<class Num_Type,
	     class Dummy = Input_Value::Num<Num_Type> >	    //	See note below
    class Num
	: public Input::Var<Num_Type>,
	  public Input_Value::Num<Num_Type>
    {
	public:
	    //------------
	    //  Operations

	    Num(const std::string &     name,
		const Range<Num_Type> & range = Range<Num_Type>());
		//  Construct a numeric input variable with the given name and
		//  range of valid values.  The default range is one with no
		//  bounds.
    };

    //	Note:
    //
    //	The template's 2nd argument is a workaround a bug with VC++.  For some
    //	unknown reason, if this 2nd argument is removed, the compiler will not
    //	recognize the base class Input_Value::Num<...>.  This sample code:
    //
    //	    #include "Input_Var_Num.h"
    //
    //	    void foo()
    //	    {
    //	      //long big_int;
    //	      //Input_Value::Num<long> long_value(big_int, "Big_integer");
    //
    //		Input_Var::Num<long>   long_var("Big_integer");
    //	    }
    //
    //	will cause the compiler to complain:
    //
    //	    error C2504: 'Num<long>' : base class undefined
    //
    //	However, if the first two lines of code are uncommented, the compiler
    //	is happy.  In other words, if the Input_Value::Num<...> is used before
    //	its corresponding Input_Var::Num<...>, then the base class is defined
    //	for the latter.
    //
    //	To allow the use of Input_Var::Num<...> without having to use
    //	Input_Value::Num<...>, we use the latter as a default value for the
    //	second template parameter (which is not used anywhere of course).
    //
    //	This workaround is also used for other similar template classes --
    //	Input_Var::Enum and Input_Var::Enum_List.

    //-------------------------------------------------------------------------
};


//-----------------------------------------------------------------------------

#include "Input_Var_Num.inl"

//-----------------------------------------------------------------------------

#endif
