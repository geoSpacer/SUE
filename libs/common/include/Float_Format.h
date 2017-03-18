#ifndef COMMON_LIB__FLOAT_FORMAT_H
#define COMMON_LIB__FLOAT_FORMAT_H

//-----------------------------------------------------------------------------

#include <string>

#include "Numeric_Format.h"

//-----------------------------------------------------------------------------

//  Class:  Float_Format
//
//  This abstract class represents a format specification for a floating-point
//  value.

class Float_Format
    : public Numeric_Format
{
    public :
	//------------
	//  Operations

	Float_Format(bool show_pos_sign,
		     char pos_sign);
	    //	Create a format; if {show_pos_sign} is true, then use
	    //	{pos_sign} as the sign character for positive numbers.

	virtual
	    std::string operator()(double value) const = 0;
	    //	Format the given floating-point value.
};

//-----------------------------------------------------------------------------

//  Operator: <<
//
//  This operator is provided as a shorthand for accessing the operator()
//  of the Float_Format class.  Example:
//
//	std::cout << ( Fix_Fmt('+',5,3) << some_float_var );

std::string operator<<(const Float_Format & fmt,
		       double		    d);

//-----------------------------------------------------------------------------

#include "Float_Format.inl"

//-----------------------------------------------------------------------------

#endif
