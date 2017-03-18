//-----------------------------------------------------------------------------
//  Inline function definitions:  Input::Var class template
//-----------------------------------------------------------------------------

namespace Input
{
    //-------------------------------------------------------------------------

    template<class Value_Type>
    Var<Value_Type>::Var()
    {
    }

    //-------------------------------------------------------------------------

    template<class Value_Type>
    inline
    Value_Type Var<Value_Type>::value() const
    {
	return value_;
    }

    //-------------------------------------------------------------------------

    template<class Value_Type>
    inline
    Value_Type & Var<Value_Type>::location()
    {
	return value_;
    }

    //-------------------------------------------------------------------------
};
