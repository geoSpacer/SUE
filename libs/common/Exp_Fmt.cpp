//-----------------------------------------------------------------------------
//  Class implementation:  Exp_Fmt
//-----------------------------------------------------------------------------

#include "Exp_Fmt.h"
#include "Assert_That.h"

//-----------------------------------------------------------------------------

namespace
{
    const char default_letter = 'e';
};

//-----------------------------------------------------------------------------

Exp_Fmt::Exp_Fmt(int num_digits)
    : Numeric_Format(false, ' '),
      num_digits_(num_digits),
      exp_letter_(default_letter)
{
    ASSERT_THAT(1 <= num_digits && num_digits <= 3)
}

//-----------------------------------------------------------------------------

Exp_Fmt::Exp_Fmt(char exp_letter,
		 int  num_digits)
    : Numeric_Format(false, ' '),
      num_digits_(num_digits),
      exp_letter_(exp_letter)
{
    ASSERT_THAT(1 <= num_digits && num_digits <= 3)
}

//-----------------------------------------------------------------------------

Exp_Fmt::Exp_Fmt(char exp_letter,
		 char pos_sign,
		 int  num_digits)
    : Numeric_Format(true, pos_sign),
      num_digits_(num_digits),
      exp_letter_(exp_letter)
{
    ASSERT_THAT(1 <= num_digits && num_digits <= 3)
}


//-----------------------------------------------------------------------------

int Exp_Fmt::width() const
{
    int width = num_digits() + 1;	    //	"1" is for exponent letter
    if (show_pos_sign())
	width++;
    return width;
}

//-----------------------------------------------------------------------------
//  Class Attributes
//-----------------------------------------------------------------------------

const Exp_Fmt Exp_Fmt::default_format('e','+',3);
