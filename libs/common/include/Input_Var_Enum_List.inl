//-----------------------------------------------------------------------------
//  Inline function definitions:  Input_Var::Enum_List class template
//-----------------------------------------------------------------------------

namespace Input_Var
{
    //-------------------------------------------------------------------------

    template<class Enum_Type,
	     class Dummy>
    Enum_List<Enum_Type>::Enum_List(const std::string &		      name,
				    const std::string &		      desc,
				    Str_To_Value<Enum_Type>::Func_Ptr function)
	: Input::Var_With_List<Enum_Type>(),
	  Formatted_Value(name, desc),
	  Input_Value::Enum_List<Enum_Type>(location(), name, desc, function)
    {
    }

    //-------------------------------------------------------------------------
};
