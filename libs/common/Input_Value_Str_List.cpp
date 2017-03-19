//-----------------------------------------------------------------------------
//  Class implementation:  Input_Value::Str_List
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include "Input_Value_Str_List.h"

//-----------------------------------------------------------------------------

namespace Input_Value
{
    //-------------------------------------------------------------------------

    Str_List::Str_List(std::vector<std::string> & location,
		       const std::string &	  name)
	: Location< std::vector<std::string> >(location),
	  Input::Value(name)
    {
    }

    //-------------------------------------------------------------------------

    void Str_List::read(std::istringstream & strm)
	throw(Input_Value::Error)
    {
	std::string word;

	while (strm >> word) {
	    location_.push_back(word);
	}
    }

    //-------------------------------------------------------------------------
};
