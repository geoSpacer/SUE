#ifndef COMMON_LIB__INPUT_VALUE_ENUM_LIST_H
#define COMMON_LIB__INPUT_VALUE_ENUM_LIST_H

//-----------------------------------------------------------------------------

#include <string>
#include <vector>

#include "Input_Value_Location.h"
#include "Input_Formatted_Value.h"
#include "Input_Value_Format_Error.h"
#include "Str_To_Value.h"

//-----------------------------------------------------------------------------

//  Class:  Input_Value::Enum_List<class Enum_Type>
//
//  Template parameters:
//	Enum_Type = an enumerated type (e.g., Month)
//
//  This represents an input value of a list of values of an enumerated type
//  {Enum_Type}.  Acceptable input values are those strings which represent
//  a list of specific enumerated values for the given type.

namespace Input_Value
{
    //-------------------------------------------------------------------------

    template<class Enum_Type>
    class Enum_List
	: public	 Location< std::vector<Enum_Type> >,
	  public virtual Input::Formatted_Value
    {
	public:
	    //------------
	    //  Operations

	    Enum_List(std::vector<Enum_Type> &		location,
		      const std::string &		name,
		      const std::string &		description,
		      Str_To_Value<Enum_Type>::Func_Ptr str_to_enum_func =
							Str_To_Value<Enum_Type>
							::default_func());
		//  Construct an input value for a list of enumerated values
		//  with the given location, name, and description (= a brief
		//  phrase describing what sort of input-value the enumerated
		//  type expects, e.g., "a month abbreviation (3-letter)".
		//  The {str_to_enum_func} is the function used for converting
		//  a string (word) into a value of the enumerated type.

	    void read(std::istringstream & strm)
		    throw(Input_Value::Error);
		//  Read a list of whitespace-separated enumerated input values
		//  from a string stream.

	//---------------------------------------------------------------------

	private :
	    Str_To_Value<Enum_Type>::Func_Ptr str_to_enum_func_;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "Input_Value_Enum_List.inl"

//-----------------------------------------------------------------------------

#endif
