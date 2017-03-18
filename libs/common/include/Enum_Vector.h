#ifndef COMMON_LIB__ENUM_VECTOR_H
#define COMMON_LIB__ENUM_VECTOR_H

//----------------------------------------------------------------------------

#include <vector>

//----------------------------------------------------------------------------

//  Class:  Enum::Vector<class Enum_Type,
//			 class Elem_Type>
//
//  This template class represents a vector indexed by an enumerated type.
//  The only restriction on the type for the vector's elements is that it
//  must have a default constructor if the vector is constructed without an
//  initial value for its elements.
//
//  In order to use this template class for an enumerated type {Enum_Type},
//  there must be 2 functions defined for the type:
//
//	unsigned int Enum::Sequence<Enum_Type>::count();
//	    //	Returns the total number of distinct values in the sequence
//	    //	for the enumerated type.
//
//	unsigned int Enum::Sequence<Enum_Type>::position(Enum_Type value);
//	    //	Returns the position of the given value in the sequence of
//	    //	values for the type.  Positions are numbered from 0 on, so
//	    //	the first value in the sequence has position 0, the second
//	    //	value has position 1, etc.
//
//  Note that these two functions are also required for the template class
//  Enum::Circulator.  The functions are already declared by using the
//  Enum::Sequence template class, so the programmer need only include that
//  header file in the source file where the code for the functions resides.

namespace Enum
{

    template<class Enum_Type,
	     class Elem_Type>
    class Vector
    {
	public :
	    //------------
	    //	Operations

	    Vector();
		//  Construct a vector and initialize all its elements to the
		//  default value of Elem_Type

	    Vector(const Elem_Type & initial_value);
		//  Construct a vector and initialize all its elements to the
		//  given value.

	    Vector(const Vector<Enum_Type, Elem_Type> & vector);
		//  Construct a vector and initialize its elements from the
		//  given vector.

	    const Elem_Type & operator[](const Enum_Type & value) const;
		//  Read-only access the element for the given enumerated
		//  value.
			
	    Elem_Type & operator[](const Enum_Type & value);
		//  Read-and-write access the element for the given enumerated
		//  value.

	    Vector<Enum_Type, Elem_Type> & operator=(
		    const Vector<Enum_Type, Elem_Type> & vector);
		//  Assign the values in the given vector to our elements.

	//---------------------------------------------------------------------

	private :
	    std::vector<Elem_Type> vec_;
    };

};

//----------------------------------------------------------------------------

#include "Enum_Vector.inl"

//----------------------------------------------------------------------------

#endif
