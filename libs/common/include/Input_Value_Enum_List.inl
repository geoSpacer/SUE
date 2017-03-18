//-----------------------------------------------------------------------------
//  Inline function definitions:  Input_Value::Enum_List class template
//-----------------------------------------------------------------------------

namespace Input_Value
{
    //-------------------------------------------------------------------------

    template<class Enum_Type>
    Enum_List<Enum_Type>::Enum_List(std::vector<Enum_Type> &	      location,
				    const std::string &		      name,
				    const std::string &		      desc,
				    Str_To_Value<Enum_Type>::Func_Ptr function)
	: Location< std::vector<Enum_Type> >(location),
	  Formatted_Value(name, desc),
	  str_to_enum_func_(function)
    {
    }

    //-------------------------------------------------------------------------

    template<class Enum_Type>
    void Enum_List<Enum_Type>::read(std::istringstream & strm)
	throw(Input_Value::Error)
    {
	int count = 0;
	std::string word;

	while (strm >> word) {
	    Enum_Type value;
	    if (! str_to_enum_func_(word, value)) {
		throw Input_Value_Error::Bad_Format(*this, word);
	    }
	    location_.push_back(value);
	    if (count > 0)
		str_ += " ";
	    str_ += word;
	}
    }

    //-------------------------------------------------------------------------
};
