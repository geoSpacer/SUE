#ifndef COMMON_LIB__ALL_WHITESPACE_H
#define COMMON_LIB__ALL_WHITESPACE_H

//-----------------------------------------------------------------------------

#include <string>
#include <sstream>

//-----------------------------------------------------------------------------

bool all_whitespace(std::istringstream & strm,
		    std::string &	 text,
		    unsigned int	 num_chars = 0);

    //  Determine if the remaining characters in a input string stream are all
    //	whitespace characters.  If the function finds a non-whitespace
    //	character, it will attempt to read upto a specified # of characters
    //	total (parameter {num_chars}).  If {num_chars} is 0, then the function
    //	will read non-whitespace characters until a whitespace character or the
    //	end of the stream.  The function will assign these characters to the
    //	parameter {text} surrounded by double quotes, i.e, "{characters}".  If
    //	there are more characters in the stream after these characters, the
    //	function will append " ..." to the {text} parameter, i.e.,
    //
    //	    "{characters}" ...
    //
    //  Return value:
    //	    true    The stream had no characters left, or it had one or more
    //		    whitespace characters only.
    //
    //	    false   0 or more whitespace characters were skipped until a non-
    //		    whitespace character was found.  Starting with this
    //		    character, upto {num_chars} characters were read from the
    //		    stream and assigned to {text}.

bool all_whitespace(const std::string & str,
		    std::string &	text,
		    unsigned int	num_chars = 0);
    //	This variation of the function checks if the given string has no
    //	characters or all whitespace characters.

bool all_whitespace(std::istringstream & strm);
bool all_whitespace(const std::string & str);
    //	These variations of the function simply check if all the characters
    //	in an input string stream or string are all whitespace charaacters.
    //	It does not return any non-whitespace characters it finds.

//-----------------------------------------------------------------------------

#include "all_whitespace.inl"

//-----------------------------------------------------------------------------

#endif
