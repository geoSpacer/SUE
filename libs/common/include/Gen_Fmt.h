#ifndef COMMON_LIB__GEN_FMT_H
#define COMMON_LIB__GEN_FMT_H

//-----------------------------------------------------------------------------

#include "Float_Format.h"
#include "Fix_Fmt.h"
#include "Sci_Fmt.h"

//-----------------------------------------------------------------------------

//  Class:  Gen_Fmt
//
//  This class represents a general format for floating-point numbers.  This
//  This format is a combination of a fixed and scientific formats (Fix_Fmt
//  and Sci_Fmt).  The fixed format is used unless a number cannot be
//  represented in this format, in which the scientific format is used.
//  Therefore, the scientific format is used if
//
//	A)  the number is not = 0, but the result of formatting the number
//	    with the fixed format would yield 0.
//
//	or
//
//	B)  the # of digits that the number has before the decimal point is
//	    more than the minimum specified by the fixed format.

class Gen_Fmt
    : public Float_Format
{
    public:
	//------------
	//  Operations

	Gen_Fmt(const Fix_Fmt & fix_fmt,
		const Sci_Fmt & sci_fmt);
	    //	Construct a general format with the given fixed and scientific
	    //	formats.

	std::string operator()(double value) const;
	    //	Format the given floating-point value.

	//------------
	//  Attributes

	const Fix_Fmt & fix_fmt() const;
	    //	The fixed format part of the general format.

	const Sci_Fmt & sci_fmt() const;
	    //	The fixed format part of the general format.

	int width() const;
	    //	The full width of the format in characters (the maximum width
	    //	of the fixed and scientific formats).

    //-------------------------------------------------------------------------

    private:
	//------------
	//  Attributes

	Fix_Fmt fix_fmt_;
	Sci_Fmt sci_fmt_;

	//  These attributes inherited from Numeric_Format via Float_Format
	//  are not relevant.
	bool show_pos_sign() const;
	char pos_sign() const;
};

//-----------------------------------------------------------------------------

//  Operator:  ||
//
//  This operator is defined to provided a shortcut for constructing a Gen_Fmt,
//  e.g.,
//
//	float f;
//	std::cout << ( (Fix_Fmt('+',5,3) || Sci_Fmt('+',4,Exp_Fmt(2))) << f );

Gen_Fmt operator||(const Fix_Fmt & fix_fmt,
		   const Sci_Fmt & sci_fmt);

//-----------------------------------------------------------------------------

#include "Gen_Fmt.inl"

//-----------------------------------------------------------------------------

#endif
