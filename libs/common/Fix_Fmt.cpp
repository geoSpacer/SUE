//-----------------------------------------------------------------------------
//  Class implementation:  Fix_Fmt
//-----------------------------------------------------------------------------

#include <sstream>
#include <iomanip>
#include <ios>

#include "Fix_Fmt.h"
#include "Assert_That.h"

//-----------------------------------------------------------------------------

Fix_Fmt::Fix_Fmt(int digits_after)
    : Float_Format(false, ' '),
      digits_before_(1),
      leading_0s_(false),
      digits_after_(digits_after)
{
    ASSERT_THAT(digits_after >= 0)
}

//-----------------------------------------------------------------------------

Fix_Fmt::Fix_Fmt(int digits_before,
		 int digits_after)
    : Float_Format(false, ' '),
      digits_before_(digits_before),
      leading_0s_(false),
      digits_after_(digits_after)
{
    ASSERT_THAT(digits_before > 0)
    ASSERT_THAT(digits_after >= 0)
}

//-----------------------------------------------------------------------------

Fix_Fmt::Fix_Fmt(Leading_Zeroes leading_zeroes,
		 int		digits_before,
		 int		digits_after)
    : Float_Format(false, ' '),
      digits_before_(digits_before),
      leading_0s_(true),
      digits_after_(digits_after)
{
    ASSERT_THAT(digits_before > 0)
    ASSERT_THAT(digits_after >= 0)
}

//-----------------------------------------------------------------------------

Fix_Fmt::Fix_Fmt(char pos_sign,
		 int  digits_after)
    : Float_Format(true, pos_sign),
      digits_before_(1),
      leading_0s_(false),
      digits_after_(digits_after)
{
    ASSERT_THAT(digits_after >= 0)
}

//-----------------------------------------------------------------------------

Fix_Fmt::Fix_Fmt(char pos_sign,
		 int  digits_before,
		 int  digits_after)
    : Float_Format(true, pos_sign),
      digits_before_(digits_before),
      leading_0s_(false),
      digits_after_(digits_after)
{
    ASSERT_THAT(digits_before > 0)
    ASSERT_THAT(digits_after >= 0)
}

//-----------------------------------------------------------------------------

Fix_Fmt::Fix_Fmt(char		pos_sign,
		 Leading_Zeroes leading_zeroes,
		 int		digits_before,
		 int		digits_after)
    : Float_Format(true, pos_sign),
      digits_before_(digits_before),
      leading_0s_(true),
      digits_after_(digits_after)
{
    ASSERT_THAT(digits_before > 0)
    ASSERT_THAT(digits_after >= 0)
}

//-----------------------------------------------------------------------------

std::string Fix_Fmt::operator()(double value) const
{
    int width = digits_before();
    if (digits_after() > 0)
	width += 1 + digits_after();    // include "."

    std::ostringstream strm;
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
    strm << std::fixed << std::setw(width)
	 << std::setprecision(digits_after()) << value;

    if (replace_plus) {
	std::string str = strm.str();
	str[str.find('+')] = pos_sign();
	return str;
    }

    return strm.str();
}

//-----------------------------------------------------------------------------

int Fix_Fmt::width() const
{
    int width = digits_before_;
    if (show_pos_sign())
	width++;
    if (digits_after_ > 0)
	width += 1 + digits_after_;	//  1 extra is for decimal point
    return width;
}
