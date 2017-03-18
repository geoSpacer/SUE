//-----------------------------------------------------------------------------
//  Inline function definitions:  Input_Value::Num class template
//-----------------------------------------------------------------------------

#include "Str_To_Value.h"

//-----------------------------------------------------------------------------

namespace Input_Value
{
    //-------------------------------------------------------------------------

    template<class Num_Type>
    Num<Num_Type>::Num(Num_Type &	       location,
		       const std::string &     name,
		       const Range<Num_Type> & range)
	: Location<Num_Type>(location),
	  Formatted_Value(name, type_description()),
	  range_(range)
    {
    }

    //-------------------------------------------------------------------------

    template<class Num_Type>
    void Num<Num_Type>::read(std::istringstream & strm)
	throw(Input_Value::Error)
    {
	std::string s;

	if (strm >> s) {
	    Num_Type value;
	    if (Str_To_Value<Num_Type>::default_func()(s, value)) {
		if (range_.contains(value)) {
		    location_ = value;
		    str_ = s;
		}
		else
		    throw Input_Value_Error::Not_In_Range(*this, s,
							  range_.str(name()));
	    }
	    else {
		if (is_valid_number(s))
		    throw Input_Value_Error::Too_Big(*this, s);
		else
		    throw Input_Value_Error::Bad_Format(*this, s);
	    }
	}
	else
	    throw Input_Value_Error::Missing(*this);
    }

    //-------------------------------------------------------------------------
};
