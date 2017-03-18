//-----------------------------------------------------------------------------
//  Inline function definitions:  Input_Var::Enum class template
//-----------------------------------------------------------------------------

namespace Input_Var
{
    //-------------------------------------------------------------------------

    template<class Enum_Type,
	     class Dummy>
    Enum<Enum_Type>::Enum(const std::string &		    name,
			  const std::string &		    description,
			  Str_To_Value<Enum_Type>::Func_Ptr function)
	: Input::Var<Enum_Type>(),
	  Formatted_Value(name, description),
	  Input_Value::Enum<Enum_Type>(location(), name, description, function)
    {
    }

    //-------------------------------------------------------------------------
};
