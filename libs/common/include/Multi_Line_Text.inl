//-----------------------------------------------------------------------------
//  Inline function definitions:  Multi_Line_Text class
//				  Operator+
//-----------------------------------------------------------------------------

inline
const std::string & Multi_Line_Text::line(int i) const
{
    return operator[](i);
}

//-----------------------------------------------------------------------------

inline
Multi_Line_Text::operator const std::vector<std::string> &() const
{
    return lines_;
}

//-----------------------------------------------------------------------------

inline
int Multi_Line_Text::line_count() const
{
    return lines_.size();
}

//-----------------------------------------------------------------------------
//  Operator+
//-----------------------------------------------------------------------------

inline
Multi_Line_Text operator+(const Multi_Line_Text & text,
			  const char *		  line)
{
    return text + std::string(line);
}
