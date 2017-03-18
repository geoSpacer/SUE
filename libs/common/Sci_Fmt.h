#ifndef COMMON_LIB__SCI_FMT_H
#define COMMON_LIB__SCI_FMT_H

//-----------------------------------------------------------------------------

#include "default_precision.h"
#include "Float_Format.h"
#include "Exp_Fmt.h"

//-----------------------------------------------------------------------------

//  Class:  Sci_Fmt
//
//  This class represents the scientific format for floating-point numbers.
//  This format has one digit before the decimal point, 0 or more digits after
//  the decimal point, and an exponent (see the class Exp_Fmt for details on
//  formatting exponents).
//
//  Examples:
//			Sign for	# of digits
//			positive #s	after the "."
//
//	Sci_Fmt()	    none	default: 6
//	Sci_Fmt(5)	    none	    5
//	Sci_Fmt('+')	    '+'		default: 6
//	Sci_Fmt('+',3)	    '+'		    3
//
//	    In the examples above, the default exponent format is used.
//	    An exponent format can be explicitly specified as well.
//
//	Sci_Fmt(Exp_Fmt('E',2))
//	Sci_Fmt(5, Exp_Fmt('e','+',3))
//	Sci_Fmt('+', Exp_Fmt('E'))
//	Sci_Fmt('+',3, Exp_Fmt('E','+'))

class Sci_Fmt
    : public Float_Format
{
    public :
	//------------
	//  Operations

	Sci_Fmt(const Exp_Fmt & exp_fmt = Exp_Fmt::default_format);
	    //	Create a format with the default # of digits after the decimal
	    //	point, and the given exponent format.  Positive values have
	    //	no sign character.

	Sci_Fmt(char		pos_sign,
		const Exp_Fmt & exp_fmt = Exp_Fmt::default_format);
	    //	Create a format with the default # of digits after the decimal
	    //	point, and the given exponent format.  Positive values have
	    //	the given sign character.

	Sci_Fmt(int		digits_after,
		const Exp_Fmt & exp_fmt	    = Exp_Fmt::default_format);
	    //	Create a format with the given # of digits after the decimal
	    //	point, and the given exponent format.  Positive values have
	    //	no sign character.

	Sci_Fmt(char		pos_sign,
		int		digits_after,
		const Exp_Fmt & exp_fmt	    = Exp_Fmt::default_format);
	    //	Create a format with the given # of digits after the decimal
	    //	point, and the given exponent format.  Positive values have
	    //	the given sign character.

	std::string operator()(double value) const;
	    //	Format the given floating-point value.

	//------------
	//  Attributes

	int digits_after() const;
	    //	The # of digits after the ".".

	const Exp_Fmt & exponent() const;
	    //	The format for the exponent.

	int width() const;
	    //	The full width of the format in characters.

    private :
	int	digits_after_;
	Exp_Fmt exp_fmt_;
};

//-----------------------------------------------------------------------------

#include "Sci_Fmt.inl"

//-----------------------------------------------------------------------------

#endif
