#ifndef COMMON_LIB__STR_TO_VALUE_H
#define COMMON_LIB__STR_TO_VALUE_H

//-----------------------------------------------------------------------------

//  Class:  Str_To_Value<class Value_Type>
//
//  Template parameter:
//	Value_Type = a type whose values have a certain format
//
//  This template class encapsulates functions for converting a string to
//  values of other types (e.g., numeric or enumerated types).

template<class Value_Type>
class Str_To_Value
{
    public:
	typedef bool (*Func_Ptr)(const std::string & str,
				 Value_Type &	     object);
	    //	A typedef for a pointer to a function that converts a string
	    //	value into a value of the desired type.  If the conversion
	    //	succeeds, the function assigns the new value to the specified
	    //	object, and returns "true".  If the conversion fails, the
	    //	function returns "false".

	static Func_Ptr default_func();
	    //	Returns the default function for converting strings to values
	    //	for the desired type {Value_Type}.
};

//-----------------------------------------------------------------------------

#endif
