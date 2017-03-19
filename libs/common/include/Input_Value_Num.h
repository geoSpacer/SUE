#ifndef COMMON_LIB__INPUT_VALUE_NUM_H
#define COMMON_LIB__INPUT_VALUE_NUM_H

//-----------------------------------------------------------------------------

#include <string>

#include "Input_Value_Location.h"
#include "Input_Formatted_Value.h"
#include "Range.h"
#include "Input_Value_Format_Error.h"

//-----------------------------------------------------------------------------

//  Class:  Input_Value::Num<class Num_Type>
//
//  Template parameters:
//	Num_Type = a numeric type (e.g., int, float)
//
//  This abstract class represent a numeric input value.  Such a value has a
//  range of acceptable values.

namespace Input_Value
{
    //-------------------------------------------------------------------------

    template<class Num_Type>
    class Num
	: public Location<Num_Type>,
	  public virtual Input::Formatted_Value
    {
	public:
	    //------------
	    //  Operations

	    Num(Num_Type &		location,
		const std::string &	name,
		const Range<Num_Type> & range = Range<Num_Type>());
		//  Construct a numeric input value with the given location,
		//  name and range.  The default range is one with no lower
		//  or upper bounds.

	    void read(std::istringstream & strm)
		    throw(Input_Value::Error);
		//  Read a numeric input value from a string stream.

	    //------------------
	    //  Class Attributes

	    static const char * type_description();
		// The description of the numeric type.

	    static bool is_valid_number(const std::string & str);
		//  Return "true" is the string is a properly formatted number.
		//  This function is used when the conversion of a value as a
		//  string to the numeric type {Num_Type} fails, to see if the
		//  failure is due to the number being too big.

	//---------------------------------------------------------------------

	private:
	    Range<Num_Type> range_;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "Input_Value_Num.inl"

//-----------------------------------------------------------------------------

#endif
