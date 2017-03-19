#ifndef COMMON_LIB__MULTI_LINE_TEXT_H
#define COMMON_LIB__MULTI_LINE_TEXT_H

//-----------------------------------------------------------------------------

#include <string>
#include <sstream>
#include <vector>

//-----------------------------------------------------------------------------

//  Class:  Multi_Line_Text
//
//  This class represents text that has multiple lines.  It's typically
//  used for error messages and column titles.

class Multi_Line_Text
{
    public :
	//------------
	//  Operations

	Multi_Line_Text();
	    //	Construct with no lines

	Multi_Line_Text(const char *	    line);
	Multi_Line_Text(const std::string & line);
	    //	Construct with one line.

	Multi_Line_Text(const std::vector<std::string> & lines);
	    //	Construct with several lines.

	Multi_Line_Text(const std::ostringstream & strm);
	    //	Construct from a string stream; the lines in the stream
	    //	are separated by newlines.  The number of lines is equal to
	    //	the number of newlines plus 1.  For example, if the stream
	    //	has two newlines, the line count will be 3.  Therefore, do NOT
	    //	terminate the last line with a newline.

	Multi_Line_Text & operator+=(const std::string & line);
	    //	Append a new line to the text.

	Multi_Line_Text & operator+=(const std::vector<std::string> & lines);
	    //	Append a sequence of new lines to the text.

	const std::string & operator[](int i) const;
	const std::string & line(int i) const;
	    //	Return the line at position {i}.  The first line is at
	    //	position 0, 2nd line at position 1, etc; therefore {i} must
	    //	be = or > 0 and < line_count().

	operator const std::vector<std::string> &() const;
	    //	Convert to a vector of strings.

	//------------
	//  Attributes

	int line_count() const;
	    //	The number of lines in the text (= or > 0).

    private :
	std::vector<std::string> lines_;
};

//-----------------------------------------------------------------------------

//  Operator: +
//
//  This operator adds a single line or a set of lines to a Multi_Line_Text,
//  creating a Multi_Line_Text object.

Multi_Line_Text operator+(const Multi_Line_Text & text,
			  const char *		  line);

Multi_Line_Text operator+(const Multi_Line_Text & text,
			  const std::string &	  line);

Multi_Line_Text operator+(const Multi_Line_Text &	   text,
			  const std::vector<std::string> & lines);

//-----------------------------------------------------------------------------

#include "Multi_Line_Text.inl"

//-----------------------------------------------------------------------------

#endif
