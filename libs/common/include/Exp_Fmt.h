#ifndef COMMON_LIB__EXP_FMT_H
#define COMMON_LIB__EXP_FMT_H

//-----------------------------------------------------------------------------

#include "Numeric_Format.h"

//-----------------------------------------------------------------------------

//  Class:  Exp_Fmt
//
//  This class represents the format for an exponent when using scientific
//  format (i.e., class Sci_Fmt) for floating-point numbers.
//
//  Examples:
//			    If the exponent is ---->	3	-7	20
//			    then the format yields:
//	Exp_Fmt()					e3	e-7	e20
//	Exp_Fmt(3)					e003	e-007	e020
//	Exp_Fmt('E')					E3	E-7	E20
//	Exp_Fmt('E',2)					E03	E-07	E20
//	Exp_Fmt('e','+')				e+3	e-7	e+20
//	Exp_Fmt('E','+',3)				E+003	E-007	E+020
//

class Exp_Fmt
    : public Numeric_Format
{
    public :
	//------------
	//  Operations

	Exp_Fmt(int num_digits = 1);
	    //	Create a format with the letter 'e', no sign character for
	    //	positive #s, and the given # of digits (padded with leading
	    //	zeroes).

	Exp_Fmt(char exp_letter,
		int  num_digits = 1);
	    //	Create a format with the given letter, no sign character for
	    //	positive #s, and the given # of digits (padded with leading
	    //	zeroes).

	Exp_Fmt(char exp_letter,
		char pos_sign,
		int  num_digits = 1);
	    //	Create a format with the given letter, sign character for
	    //	positive #s, and # of digits (padded with leading zeroes).

	//------------
	//  Attributes

	int num_digits() const;
	    //	The number of digits to use.

	char exp_letter() const;
	    //	Return the exponent's initial letter.

	int width() const;
	    //	The full width of the format in characters.

	static const Exp_Fmt default_format;
	    //	Default exponent format = Exp_Fmt('e', '+', 3)

    //-------------------------------------------------------------------------

    private :
	int  num_digits_;
	char exp_letter_;    //	initial letter of exponent
};

//-----------------------------------------------------------------------------

#include "Exp_Fmt.inl"

//-----------------------------------------------------------------------------

#endif
