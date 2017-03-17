#include "pragmas.h"

#include <sstream>

#include "Input_Text_File.h"
#include "all_whitespace.h"

#include "no_lines_after.h"

//-----------------------------------------------------------------------------

void no_lines_after(const std::string & last_line_desc,
		    Input::Text_File &  file)
{
    std::string line;
    if (file.read_line(line)) {
	std::string extra_text;
	if (! all_whitespace(line, extra_text)) {
	    std::ostringstream mesg;
	    mesg << "Extra text found after the " << last_line_desc << ":\n"
		 << "  " << extra_text;
	    throw file.error(mesg);
	}
    }
}
