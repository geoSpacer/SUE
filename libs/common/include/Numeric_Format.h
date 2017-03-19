#ifndef COMMON_LIB__NUMERIC_FORMAT_H
#define COMMON_LIB__NUMERIC_FORMAT_H

//-----------------------------------------------------------------------------

//  Class:  Numeric_Format
//
//  This abstract class represents a format specification for a numeric value.

class Numeric_Format
{
    public :
	//------------
	//  Operations

	Numeric_Format(bool show_pos_sign,
		       char pos_sign);
	    //	Create a format; if {show_pos_sign} is true, then use
	    //	{pos_sign} as the sign character for positive numbers.

	//------------
	//  Attributes

	bool show_pos_sign() const;
	    //	Use a sign character for positive numbers?

	char pos_sign() const;
	    //	The sign character for positive numbers.

	virtual
	    int width() const = 0;
	    //	The full width of the format in characters.

    private :
	bool show_pos_sign_;
	char pos_sign_;
};

//-----------------------------------------------------------------------------

#include "Numeric_Format.inl"

//-----------------------------------------------------------------------------

#endif
