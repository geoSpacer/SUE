//-----------------------------------------------------------------------------
//  Inline function definitions:  Enum::Vector class template
//-----------------------------------------------------------------------------

#include "Enum_Sequence.h"

//-----------------------------------------------------------------------------

template<class Enum_Type,
	 class Elem_Type>
Enum::Vector<Enum_Type, Elem_Type>::Vector()
    : vec_(Enum::Sequence<Enum_Type>::count())
{
}

//-----------------------------------------------------------------------------

template<class Enum_Type,
	 class Elem_Type>
Enum::Vector<Enum_Type, Elem_Type>::Vector(const Elem_Type & initial_value)
    : vec_(Enum::Sequence<Enum_Type>::count(),
	   initial_value)
{
}

//-----------------------------------------------------------------------------

template<class Enum_Type,
	 class Elem_Type>
Enum::Vector<Enum_Type, Elem_Type>::Vector(const Enum::Vector<Enum_Type,
							      Elem_Type> & v)
    : vec_(v.vec_)
{
}

//-----------------------------------------------------------------------------

template<class Enum_Type,
	 class Elem_Type>
inline
const Elem_Type & Enum::Vector<Enum_Type,
			       Elem_Type>::operator[](const Enum_Type & value)
	const
{
    return vec_[Enum::Sequence<Enum_Type>::position(value)];
}

//-----------------------------------------------------------------------------

template<class Enum_Type,
	 class Elem_Type>
inline
Elem_Type & Enum::Vector<Enum_Type,
			 Elem_Type>::operator[](const Enum_Type & value)
{
    return vec_[Enum::Sequence<Enum_Type>::position(value)];
}

//-----------------------------------------------------------------------------

template<class Enum_Type,
	 class Elem_Type>
Enum::Vector<Enum_Type, Elem_Type> &
	Enum::Vector<Enum_Type,
		     Elem_Type>::operator=(const Enum::Vector<Enum_Type,
							      Elem_Type> & v)
{
    if (this != &v)
	vec_ = v.vec_;
    return *this;
}
