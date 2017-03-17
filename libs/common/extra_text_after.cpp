#include "extra_text_after.h"

#include "all_whitespace.h"

//-----------------------------------------------------------------------------

bool extra_text_after(const std::string &  last_expected,
		      std::istringstream & input_line,
		      std::ostringstream & message)
{
    std::string extra_text;
    if (all_whitespace(input_line, extra_text))
	return false;

    message << "Extra text after the \"" << last_expected << ":\n"
	       "  " << extra_text;
    return true;
}
