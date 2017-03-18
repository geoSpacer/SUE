//-----------------------------------------------------------------------------
//  Inline function definitions:  all_whitespace
//-----------------------------------------------------------------------------

inline
bool all_whitespace(const std::string & str,
		    std::string &	text,
		    unsigned int	num_chars)
{
    return all_whitespace(std::istringstream(str), text, num_chars);
}

//-----------------------------------------------------------------------------

inline
bool all_whitespace(std::istringstream & strm)
{
    std::string dummy;
    return all_whitespace(strm, dummy);
}

//-----------------------------------------------------------------------------

inline
bool all_whitespace(const std::string & str)
{
    return all_whitespace(std::istringstream(str));
}
