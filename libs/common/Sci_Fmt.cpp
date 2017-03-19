//-----------------------------------------------------------------------------
//  Class implementation:  Sci_Fmt
//-----------------------------------------------------------------------------

#include <sstream>
#include <iomanip>
#include <ios>

#include "Sci_Fmt.h"
#include "default_precision.h"
#include "Assert_That.h"
#include "Int_Fmt.h"

//-----------------------------------------------------------------------------

Sci_Fmt::Sci_Fmt(const Exp_Fmt & exp_fmt)
    : Float_Format(false, ' '),
      digits_after_(default_precision),
      exp_fmt_(exp_fmt)
{
}

//-----------------------------------------------------------------------------

Sci_Fmt::Sci_Fmt(char		pos_sign,
		const Exp_Fmt & exp_fmt)
    : Float_Format(true, pos_sign),
      digits_after_(default_precision),
      exp_fmt_(exp_fmt)
{
}

//-----------------------------------------------------------------------------

Sci_Fmt::Sci_Fmt(int		 digits_after,
		 const Exp_Fmt & exp_fmt)
    : Float_Format(false, ' '),
      digits_after_(digits_after),
      exp_fmt_(exp_fmt)

{
    ASSERT_THAT(digits_after >= 1)
}

//-----------------------------------------------------------------------------

Sci_Fmt::Sci_Fmt(char		 pos_sign,
		 int		 digits_after,
		 const Exp_Fmt & exp_fmt)
    : Float_Format(true, pos_sign),
      digits_after_(digits_after),
      exp_fmt_(exp_fmt)
{
    ASSERT_THAT(digits_after >= 1)
}

//-----------------------------------------------------------------------------

std::string Sci_Fmt::operator()(double value) const
{
    std::ostringstream strm;

    bool replace_plus = false;
    if (value >= 0) {
	if (show_pos_sign()) {
	    strm << std::showpos;
	    replace_plus = (pos_sign() != '+');
	}
    }

    strm << std::scientific << std::setprecision(digits_after()) << value;

    std::string str = strm.str();
    if (replace_plus) {
	str[str.find('+')] = pos_sign();
    }

    //	Now reformat the exponent.
    //	For Visual C++ 6.0, the exponent format for std::scientific is "e+3".
    int exp_position = str.find('e');
    std::string number = str.substr(0, exp_position);
    number += exponent().exp_letter();

    std::istringstream exp_strm(str.substr(exp_position+1));
    int exponent_value;
    exp_strm >> exponent_value;
    std::string new_exponent;
    if (exponent().show_pos_sign()) {
	new_exponent = Int_Fmt('+', leading_0s,	exponent().num_digits())
		       << exponent_value;
    } else {
	new_exponent = Int_Fmt(leading_0s, exponent().num_digits())
		       << exponent_value;
    }

    return number + new_exponent;
}

//-----------------------------------------------------------------------------

int Sci_Fmt::width() const
{
    int width = 2 + digits_after() + exp_fmt_.width();
    if (show_pos_sign())
	width++;
    return width;
}
