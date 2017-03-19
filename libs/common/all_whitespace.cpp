#include "all_whitespace.h"
#include "read_chars.h"

//-----------------------------------------------------------------------------

bool all_whitespace(std::istringstream & strm,
		    std::string &	 text,
		    unsigned int	 num_chars)
{
    if (num_chars == 0) {
	//  Skip whitespace until end of stream or a word of non-whitespace
	//  characters.
	std::string word;
	if (strm >> word)
	    text = word;
	else
	    return true;
    }
    else {
	//  Skip whitespace until end of stream or first non-whitespace
	//  character.
	char ch;
	if (strm >> ch)
	    text = ch + read_chars(strm, num_chars - 1);
	else
	    return true;
    }

    //	We have some non-whitespace characters.  Check if any more characters.
    text = std::string("\"") + text + "\"";
    char ch;
    if (strm.get(ch))
	text += " ...";

    return false;
}
