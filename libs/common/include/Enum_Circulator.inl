//-----------------------------------------------------------------------------
//  Inline function definitions:  Enum::Circulator class template
//-----------------------------------------------------------------------------

#include "Enum_Sequence.h"

//-----------------------------------------------------------------------------

template<class Enum_Type>
Enum::Circulator<Enum_Type>::Circulator()
    : Enum::Circulator_Base()
{
}

//-----------------------------------------------------------------------------

template<class Enum_Type>
inline
Enum::Circulator<Enum_Type>::operator Enum_Type() const
{
    return value_;
}

//-----------------------------------------------------------------------------

template<class Enum_Type>
void Enum::Circulator<Enum_Type>::from(Enum_Type	  start,
				       Forward_or_Reverse direction,
				       Enum_Type	  end)
{
    value_ = start;

    unsigned int start_pos = Enum::Sequence<Enum_Type>::position(start);
    unsigned int end_pos   = Enum::Sequence<Enum_Type>::position(end);
    set_count(start_pos, end_pos, direction,
	      Enum::Sequence<Enum_Type>::count());
}

//-----------------------------------------------------------------------------

template<class Enum_Type>
void Enum::Circulator<Enum_Type>::step_forward()
{
    ++value_;
}

//-----------------------------------------------------------------------------

template<class Enum_Type>
void Enum::Circulator<Enum_Type>::step_backward()
{
    --value_;
}
