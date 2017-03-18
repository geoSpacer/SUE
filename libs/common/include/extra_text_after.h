#ifndef COMMON_LIB__EXTRA_TEXT_AFTER_H
#define COMMON_LIB__EXTRA_TEXT_AFTER_H

//-----------------------------------------------------------------------------

#include <string>
#include <sstream>

//-----------------------------------------------------------------------------

bool extra_text_after(const std::string &  last_expected,
		      std::istringstream & input_line,
		      std::ostringstream & message);
    //	Is there extra text after the last expected item on the given input
    //	line?
    //
    //	Returns:
    //	    true    There is text after the last item, and a message
    //		    with the text has been written to {message}.
    //	    false   There is no extra text.

//-----------------------------------------------------------------------------

#endif
