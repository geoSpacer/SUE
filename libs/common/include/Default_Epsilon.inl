//-----------------------------------------------------------------------------
//  Inline function definitions:  Default_Epsilon class template
//-----------------------------------------------------------------------------

#include <limits>

//-----------------------------------------------------------------------------

template<class Flt_Pt_Type>
inline
Flt_Pt_Type Default_Epsilon<Flt_Pt_Type>::value()
{
    return value_;
}

//-----------------------------------------------------------------------------

template<class Flt_Pt_Type>
inline
void Default_Epsilon<Flt_Pt_Type>::set(Flt_Pt_Type new_value)
{
    value_ = new_value;
}

//-----------------------------------------------------------------------------

template<class Flt_Pt_Type>
inline
void Default_Epsilon<Flt_Pt_Type>::reset()
{
    value_ = std::numeric_limits<Flt_Pt_Type>::epsilon();
}
