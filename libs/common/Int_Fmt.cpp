//-----------------------------------------------------------------------------
//  Class implementation:  Int_Fmt
//-----------------------------------------------------------------------------

#include <sstream>
#include <iomanip>
#include <ios>

#include "Int_Fmt.h"
#include "Assert_That.h"

//-----------------------------------------------------------------------------

Int_Fmt::Int_Fmt(int num_digits)
    : Numeric_Format(false, ' '),
      num_digits_(num_digits),
      leading_0s_(false)
{
    ASSERT_THAT(num_digits >= 1)
}

//-----------------------------------------------------------------------------

Int_Fmt::Int_Fmt(Leading_Zeroes leading_zeroes,
		 int		num_digits)
    : Numeric_Format(false, ' '),
      num_digits_(num_digits),
      leading_0s_(true)
{
    ASSERT_THAT(num_digits >= 1)
}

//-----------------------------------------------------------------------------

Int_Fmt::Int_Fmt(char pos_sign,
		 int  num_digits)
    : Numeric_Format(true, pos_sign),
      num_digits_(num_digits),
      leading_0s_(false)
{
    ASSERT_THAT(num_digits >= 1)
}

//-----------------------------------------------------------------------------

Int_Fmt::Int_Fmt(char		pos_sign,
		 Leading_Zeroes leading_zeroes,
		 int		num_digits)
    : Numeric_Format(true, pos_sign),
      num_digits_(num_digits),
      leading_0s_(true)
{
    ASSERT_THAT(num_digits >= 1)
}

//-----------------------------------------------------------------------------

namespace
{
    //-------------------------------------------------------------------------

    int setup(std::ostringstream & strm,
	      bool		   negative_value,
	      const Int_Fmt &	   fmt,
	      bool &		   replace_plus)
	//  Setup a string stream for formatting an integer value with the
	//  given format.  The value is negative.  The parameter {replace_plus}
	//  indicates if a character other than '+' is going to be used.
	//  Returns the width required by the format.
    {
	int width = fmt.num_digits();

	replace_plus = false;
	if (negative_value)
	    width++;    //	add room for "-"
	else {
	    if (fmt.show_pos_sign()) {
		strm << std::showpos;
		width++;	//  add room for "+"
		replace_plus = (fmt.pos_sign() != '+');
	    }
	}

	if (fmt.leading_zeroes())
	    strm << std::setfill('0') << std::internal;

	return width;
    }

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

std::string Int_Fmt::operator()(long value) const
{
    std::ostringstream strm;
    int width = num_digits();

    bool replace_plus = false;
    if (value < 0)
	width++;    //	add room for "-"
    else {
	if (show_pos_sign()) {
	    strm << std::showpos;
	    width++;	//  add room for "+"
	    replace_plus = (pos_sign() != '+');
	}
    }

    if (leading_zeroes())
	strm << std::setfill('0') << std::internal;

    strm << std::setw(width) << value;

    std::string result = strm.str();
    if (replace_plus)
	result[result.find('+')] = pos_sign();

    return result;
}

//-----------------------------------------------------------------------------

std::string Int_Fmt::operator()(unsigned long value) const
{
    //	Note:  The std::showpos manipulator does not effect unsigned values.

    std::ostringstream strm;
    std::string result;

    if (leading_zeroes()) {
	strm << std::setfill('0') << std::internal << std::setw(num_digits())
	     << value;

	result = strm.str();
	if (show_pos_sign())
		result.insert(result.begin(), pos_sign());
    }
    else {
	strm << value;

	result = strm.str();
	int width = num_digits();
	if (show_pos_sign()) {
	    width++;
		result.insert(result.begin(), pos_sign());
	}
	if (result.size() < (unsigned) width) {
	    result.insert(0, std::string(width - result.size(), ' '));
	}
    }

    return result;
}

//-----------------------------------------------------------------------------
//  Class Attributes
//-----------------------------------------------------------------------------

const Int_Fmt Int_Fmt::default_format(1);
