//-----------------------------------------------------------------------------
//  Inline function definitions:  Input_Value::Enum class template
//-----------------------------------------------------------------------------

namespace Input_Value
{
    //-------------------------------------------------------------------------

    template<class Enum_Type>
    Enum<Enum_Type>::Enum(Enum_Type &			    location,
			  const std::string &		    name,
			  const std::string &		    description,
			  Str_To_Value<Enum_Type>::Func_Ptr function)
	: Location<Enum_Type>(location),
	  Formatted_Value(name, description),
	  str_to_enum_func_(function)
    {
    }

    //-------------------------------------------------------------------------

    template<class Enum_Type>
    void Enum<Enum_Type>::read(std::istringstream & strm)
	throw(Input_Value::Error)
    {
	std::string s;

	if (strm >> s) {
	    if (! str_to_enum_func_(s, location_)) {
		throw Input_Value_Error::Bad_Format(*this, s);
	    }
	} else {
	    throw Input_Value_Error::Missing(*this);
	}
	str_ = s;
    }

    //-------------------------------------------------------------------------
};
