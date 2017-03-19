//-----------------------------------------------------------------------------
//  Inline function definitions:  Input_Var::Num class template
//-----------------------------------------------------------------------------

namespace Input_Var
{
    //-------------------------------------------------------------------------

    template<class Num_Type,
	     class Dummy>
    Num<Num_Type>::Num(const std::string &     name,
		       const Range<Num_Type> & range)
	: Input::Var<Num_Type>(),
	  Formatted_Value(name, type_description()),
	  Input_Value::Num<Num_Type>(location(), name, range)
    {
    }

    //-------------------------------------------------------------------------
};
