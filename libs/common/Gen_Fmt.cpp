//-----------------------------------------------------------------------------
//  Class implementation:  Gen_Fmt
//-----------------------------------------------------------------------------

#include <sstream>
#include <iomanip>
#include <ios>

#include "Gen_Fmt.h"
#include "equal.h"
#include "min_max.h"

//-----------------------------------------------------------------------------

Gen_Fmt::Gen_Fmt(const Fix_Fmt & fix_fmt,
		 const Sci_Fmt & sci_fmt)
    : Float_Format(false, ' '),
      fix_fmt_(fix_fmt),
      sci_fmt_(sci_fmt)
{
}

//-----------------------------------------------------------------------------

std::string Gen_Fmt::operator()(double value) const
{
    //	Determine the number of characters before the decimal point using the
    //	given fixed format.  It's "characters" rather than "digits" because
    //	spaces can appear for padding.
    std::string fix_str = Fix_Fmt('+', fix_fmt().digits_before(),
				       fix_fmt().digits_after()) << value;
    int chars_before;
    if (fix_fmt().digits_after() > 0) {
	chars_before = fix_str.find('.') - 1; //    minus 1 for the sign char
    } else {
	chars_before = fix_str.size() - 1;    //    minus 1 for the sign char
    }
    if (chars_before > fix_fmt().digits_before())
	return sci_fmt() << value;

    //	Check for the case where the result of the fixed format is 0, but
    //	d is not 0.
    if (fix_str.find_first_not_of("+-0. ") == std::string::npos) {
	//  Fixed-format string is just 0.
	if (! equal<double>(value, 0))
	    return sci_fmt() << value;
    }

    return fix_fmt() << value;
}

//-----------------------------------------------------------------------------

int Gen_Fmt::width() const
{
    return std::max(fix_fmt_.width(), sci_fmt_.width());
}
