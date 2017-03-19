#include <cctype>

#include "is_decimal_number.h"

//-----------------------------------------------------------------------------

bool is_decimal_number(const std::string & str)
{
    const char * p = str.c_str();

    if (*p == '-' || *p == '+')
	p++;

    //	Look for the integer part of the number.
    int has_integer_part = isdigit(*p);
    if (has_integer_part) {
	do
	    p++;
	while (isdigit(*p));
    }

    //	Look for decimal part of the number.
    int has_decimal_part = (*p == '.');
    if (has_decimal_part) {
	p++;

	//  Need one digit if no integer part.
	if (! has_integer_part && ! isdigit(*p))
	    return false;

	while (isdigit(*p))
	    p++;
    }

    if (! has_integer_part && ! has_decimal_part)
	return false;

    //	Look for exponent.
    if (*p == 'e' || *p == 'E') {
	p++;
	if (*p == '+' || *p == '-')
	    p++;

	//	Need at least one digit.
	if (! isdigit(*p))
	    return false;

	while (isdigit(*p))
	    p++;
    }

    return *p == '\0';
}
