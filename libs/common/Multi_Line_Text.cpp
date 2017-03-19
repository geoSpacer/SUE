//-----------------------------------------------------------------------------
//  Class implementation:  Multi_Line_Text
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include "Multi_Line_Text.h"
#include "Assert_That.h"

//-----------------------------------------------------------------------------

Multi_Line_Text::Multi_Line_Text()
    : lines_()
{
}

//-----------------------------------------------------------------------------

Multi_Line_Text::Multi_Line_Text(const char * line)
    : lines_()
{
    lines_.push_back(line);
}

//-----------------------------------------------------------------------------

Multi_Line_Text::Multi_Line_Text(const std::string & line)
    : lines_()
{
    lines_.push_back(line);
}

//-----------------------------------------------------------------------------

Multi_Line_Text::Multi_Line_Text(const std::vector<std::string> & lines)
    : lines_(lines)
{
}

//-----------------------------------------------------------------------------

Multi_Line_Text::Multi_Line_Text(const std::ostringstream & strm)
    : lines_()
{
    std::string str = strm.str();

    //	Loop through string as long as there are newlines in it
    std::string::size_type pos;
    while ((pos = str.find('\n')) != std::string::npos) {
	lines_.push_back(str.substr(0, pos));
	str = str.substr(pos + 1);
    }
    lines_.push_back(str);
}

//-----------------------------------------------------------------------------

const std::string & Multi_Line_Text::operator[](int line_position) const
{
    ASSERT_THAT(line_position >= 0 && line_position < line_count())
    return lines_[line_position];
}

//-----------------------------------------------------------------------------

Multi_Line_Text & Multi_Line_Text::operator+=(const std::string & line)
{
    lines_.push_back(line);
    return *this;
}

//-----------------------------------------------------------------------------

Multi_Line_Text & Multi_Line_Text::operator+=(
					const std::vector<std::string> & lines)
{
    for (unsigned int i = 0; i < lines.size(); i++)
	operator+=(lines[i]);
    return *this;
}

//-----------------------------------------------------------------------------
//  Implementation:  Operator+ involving Multi_Line_Text
//-----------------------------------------------------------------------------

Multi_Line_Text operator+(const Multi_Line_Text & text,
			  const std::string &	  line)
{
    Multi_Line_Text new_text(text);
    new_text += line;
    return new_text;
}

//-----------------------------------------------------------------------------

Multi_Line_Text operator+(const Multi_Line_Text &	   text,
			  const std::vector<std::string> & lines)
{
    Multi_Line_Text new_text(text);
    new_text += lines;
    return new_text;
}
