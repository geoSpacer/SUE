#ifndef COMMON_LIB__FIX_FMT_H
#define COMMON_LIB__FIX_FMT_H

//-----------------------------------------------------------------------------

#include "default_precision.h"
#include "Leading_Zeroes.h"
#include "Float_Format.h"

//-----------------------------------------------------------------------------

//  Class:  Fix_Fmt
//
//  This class represents a format specification for floating-point numbers.
//  Fixed format has a fixed number of digits after the decimal point.	It
//  can also have a minimum # of digits before the decimal point (as with
//  formats for integer values), an optional sign character for positive
//  values, and leading zeroes.
//
//  Fixed-format examples:
//				    Sign for   leading	min # of    # of
//				    positive   zeroes	digits	    digits
//				    numbers		before "."  after "."
//
//	Fix_Fmt()		    none	no	    1	    default: 6
//	Fix_Fmt('+')		    '+'		no	    1	    default: 6
//	Fix_Fmt(3)		    none	no	    1		3
//	Fix_Fmt(5,2)		    none	no	    5		2
//	Fix_Fmt(leading_0s,5,2)	    none	yes	    5		2
//	Fix_Fmt('+',4)		    '+'		no	    1		4
//	Fix_Fmt('+',3,2)	    '+'		no	    3		2
//	Fix_Fmt('+',leading_0s,3,2) '+'		yes	    3		2

class Fix_Fmt
    : public Float_Format
{
    public :
	//------------
	//  Operations

	Fix_Fmt(int digits_after = default_precision);
	    //	Create a format with no sign character for positive values,
	    //	no leading zeroes, at least 1 digit before the ".", and
	    //	the given # of digits after the ".".

	Fix_Fmt(int digits_before,
		int digits_after);
	    //	Create a format with no sign character for positive values,
	    //	no leading zeroes, and the given # of digits before and after
	    //	the ".".

	Fix_Fmt(Leading_Zeroes leading_zeroes,
		int	       digits_before,
		int	       digits_after);
	    //	Create a format with no sign character for positive values,
	    //	leading zeroes, and the given # of digits before and after
	    //	the ".".

	Fix_Fmt(char pos_sign,
		int  digits_after = default_precision);
	    //	Create a format with the given sign character for positive
	    //	values, no leading zeroes, at least 1 digit before the ".",
	    //	and the given # of digits after the ".".

	Fix_Fmt(char pos_sign,
		int  digits_before,
		int  digits_after);
	    //	Create a format with the given sign character for positive
	    //	values, no leading zeroes, at least the given # of digits
	    //	before the ".", and the given # of digits after the ".".

	Fix_Fmt(char	       pos_sign,
		Leading_Zeroes leading_zeroes,
		int	       digits_before,
		int	       digits_after);
	    //	Create a format with the given sign character for positive
	    //	values, leading zeroes, at least the given # of digits
	    //	before the ".", and the given # of digits after the ".".

	std::string operator()(double value) const;
	    //	Format the given floating-point value.

	//------------
	//  Attributes

	int digits_before() const;
	    //	The # of digits before the decimal point.

	bool leading_zeroes() const;
	    //	True if a number should be padded with leading 0's.

	int digits_after() const;
	    //	The # of digits after the decimal point.

	int width() const;
	    //	The full width of the format in characters.

    private :
	int  digits_before_;
	bool leading_0s_;
	int  digits_after_;
};

//-----------------------------------------------------------------------------

#include "Fix_Fmt.inl"

//-----------------------------------------------------------------------------

#endif
