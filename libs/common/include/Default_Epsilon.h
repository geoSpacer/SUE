#ifndef COMMON_LIB__DEFAULT_EPSILON_H
#define COMMON_LIB__DEFAULT_EPSILON_H

//-----------------------------------------------------------------------------

//  Class template:  Default_Epsilon
//
//  Template parameter:
//	Flt_Pt_Type = floating-point type, i.e., float, double
//
//  This class represents the default epsilon value to use when testing for
//  equality between floating-point numbers.

template<class Flt_Pt_Type>
class Default_Epsilon
{
    public :
	//------------
	//  Class Operations

	static Flt_Pt_Type value();
	    //	Return the default epsilon's value.  Initially, this is
	    //	equal to std::numeric_limits<Flt_Pt_Type>::epsilon().

	static void set(Flt_Pt_Type new_value);
	    //	Set the default epsilon to the new value.

	static void reset();
	    //	Reset the default epsilon to the standard epsilon for the
	    //	type, i.e., std::numeric_limits<Flt_Pt_Type>::epsilon().

    private :
	static Flt_Pt_Type value_;
};

//-----------------------------------------------------------------------------

#include "Default_Epsilon.inl"

//-----------------------------------------------------------------------------

#endif
