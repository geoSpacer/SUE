#ifndef COMMON_LIB__INT_FMT_H
#define COMMON_LIB__INT_FMT_H

//-----------------------------------------------------------------------------

#include <string>

#include "Numeric_Format.h"
#include "Leading_Zeroes.h"

//-----------------------------------------------------------------------------

//  Class:  Int_Fmt
//
//  This class represents a format specification for integer values.
//
//  Examples:
//				    Sign for	    Minimum #	    Leading
//				    positive #s	    of digits	    0's
//
//	Int_Fmt(4)			none		4	    no
//	Int_Fmt(leading_0s, 6)		none		6	    yes
//	Int_Fmt('+')			'+'		1	    no
//	Int_Fmt('+', 3)			'+'		3	    no
//	Int_Fmt('+', leading_0s, 5)	'+'		5	    yes

class Int_Fmt
    : public Numeric_Format
{
    public :
	//------------
	//  Operations

	Int_Fmt(int num_digits);
	    //	Create a format with the given minimum # of digits to use, and
	    //	no sign character for positive values.  Spaces are used for
	    //	padding out to the specified # of digits.

	Int_Fmt(Leading_Zeroes leading_zeroes,
		int	       num_digits);
	    //	Create a format with the given minimum # of digits to use, and
	    //	no sign character for positive values.  Leading zeroes are used
	    //	for padding.


	Int_Fmt(char pos_sign,
		int  num_digits = 1);
	    //	Create a format with the given sign character for positive
	    //	values, and the minimum # of digits.  Spaces are used for
	    //	padding.

	Int_Fmt(char	       pos_sign,
		Leading_Zeroes leading_zeroes,
		int	       num_digits);
	    //	Create a format with the given sign character for positive
	    //	values, and the minimum # of digits.  Leading zeroes are used
	    //	for padding.

	std::string operator()(long value) const;
	std::string operator()(int value) const;
	std::string operator()(unsigned long value) const;
	std::string operator()(unsigned int value) const;
	    //	Format the given integer value.

	//------------
	//  Attributes

	int num_digits() const;
	    //	The number of digits to use.

	bool leading_zeroes() const;
	    //	True if a number should be padded with leading 0's.

	int width() const;
	    //	The full width of the format in characters.

	static
	    const Int_Fmt default_format;
	    //	Default integer format: 1 digit, no sign character.

    private :
	int  num_digits_;
	bool leading_0s_;
};

//-----------------------------------------------------------------------------

//  Operator: <<
//
//  This operator is provided as a shorthand for the operator() of the
//  Int_Fmt class.  Example:
//
//	std::cout << ( Int_Fmt('+', 3) << some_int_var );

std::string operator<<(const Int_Fmt & fmt,
		       long	       i);

std::string operator<<(const Int_Fmt & fmt,
		       int	       i);

std::string operator<<(const Int_Fmt & fmt,
		       unsigned long   i);

std::string operator<<(const Int_Fmt & fmt,
		       unsigned int    i);

//-----------------------------------------------------------------------------

#include "Int_Fmt.inl"

//-----------------------------------------------------------------------------

#endif
