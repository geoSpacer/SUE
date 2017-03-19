//-----------------------------------------------------------------------------
//  Inline function definitions:  Input::Var_With_List class template
//-----------------------------------------------------------------------------

namespace Input
{
    //-------------------------------------------------------------------------

    template<class Value_Type>
    Var_With_List<Value_Type>::Var_With_List()
    {
    }

    //-------------------------------------------------------------------------

    template<class Value_Type>
    inline
    const std::vector<Value_Type> & Var_With_List<Value_Type>::values() const
    {
	return values_;
    }

    //-------------------------------------------------------------------------

    template<class Value_Type>
    inline
    std::vector<Value_Type> & Var_With_List<Value_Type>::location()
    {
	return values_;
    }

    //-------------------------------------------------------------------------
};
