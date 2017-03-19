#ifndef COMMON_LIB__NO_LINES_AFTER_H
#define COMMON_LIB__NO_LINES_AFTER_H

//-----------------------------------------------------------------------------

#include <string>

namespace Input
{
    class Text_File;
};

//-----------------------------------------------------------------------------

void no_lines_after(const std::string & last_line_desc,
		    Input::Text_File &  file);
    //	Makes sure there are no more lines after what was expected to be the
    //	last line in the file.  If there are more lines, a File::Error
    //	exception is thrown.
    //
    //	Note: Whether there are more lines or not in the file depends upon how
    //	      the file is configured to handle blank lines and comments.

//-----------------------------------------------------------------------------

#endif
