#ifndef ENUM_CONTIGUOUS_SEQUENCE_H
#define ENUM_CONTIGUOUS_SEQUENCE_H

//-----------------------------------------------------------------------------

#include "Enum_Sequence.h"

//-----------------------------------------------------------------------------

//  Class:  Enum::Contiguous_Sequence<class Enum_Type>
//
//  This template class contains some specific information about a sequence of
//  *contiguous* values for an enumerated type.

namespace Enum
{
    //-------------------------------------------------------------------------

    template<class enumType>
    class Contiguous_Sequence
    {
	public:

	    static const enumType min;
		//  Minimum value in the sequence

	    static const enumType max;
		//  Maximum value in the sequence;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

//  Define the class functions for Enum::Sequence<enumType>.

template<class enumType>
unsigned int Enum::Sequence<enumType>::count()
{
    return Enum::Contiguous_Sequence<enumType>::max -
	   Enum::Contiguous_Sequence<enumType>::min + 1;
}

//-----------------------------------------------------------------------------

template<class enumType>
unsigned int Enum::Sequence<enumType>::position(enumType value)
{
    return value - Enum::Contiguous_Sequence<enumType>::min;
}

//-----------------------------------------------------------------------------

//  Prefix ++ for enumType

template <class enumType>
enumType & operator++(enumType & var)
    //	Increment an enumerated variable's value to the next value in its
    //	sequence.  If the value is the maximum, then the variable is to the
    //	minimum.
{
    if (var == Enum::Contiguous_Sequence<enumType>::max)
	var = Enum::Contiguous_Sequence<enumType>::min;
    else
	var = enumType(var + 1);
    return var;
}

//-----------------------------------------------------------------------------

//  Prefix -- for enumType

template <class enumType>
enumType & operator--(enumType & var)
    //	Decrement an enumerated variable's value to the preceeding value in its
    //	sequence.  If the value is the minimum, then the variable is to the
    //	maximum.
{
    if (var == Enum::Contiguous_Sequence<enumType>::min)
	var = Enum::Contiguous_Sequence<enumType>::max;
    else
	var = enumType(var - 1);
    return var;
}

//-----------------------------------------------------------------------------

#endif
