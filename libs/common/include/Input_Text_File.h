#ifndef COMMON_LIB__INPUT_TEXT_FILE_H
#define COMMON_LIB__INPUT_TEXT_FILE_H

//-----------------------------------------------------------------------------

#include <string>
#include <fstream>

#include "File_Name_And_Desc.h"
#include "File_Error.h"
#include "Read_or_Skip.h"
#include "Leave_or_Remove.h"
#include "Multi_Line_Text.h"

//-----------------------------------------------------------------------------

namespace Default
{
    namespace Comment_Markers
    {
	extern const char * whole_line;
	extern const char * end_of_line;
    };
};

//-----------------------------------------------------------------------------

//  Class:  Input::Text_File
//
//  This class represents a text file from which input data is read.

namespace Input
{
    //-------------------------------------------------------------------------

    class Text_File
	: public File::Name_And_Desc
    {
	public :
	    //------------
	    //	Operations

	    Text_File(const std::string & name,
		      const std::string & description = "input text");
		//  Open a text file with the given name for input.
		//  {description} is a brief description of the file.

	    void blank_lines(Read_or_Skip read_or_skip);
		//  Determine what to do with blank lines -- either read them
		//  like any other lines, or skip them.  When a file is
		//  first opened, initial setting for blank lines is Read.

	    void comment_lines(const std::string & marker);
		//  Set the marker for comment lines.  The marker is a special
		//  sequence of non-whitespace characters that denote a line
		//  is a comment line when they are the first non-whitespace
		//  characters on the line.

	    void comment_lines(Read_or_Skip read_or_skip);
		//  Determine what to do with comment lines -- either read
		//  them like any other lines, or skip them.  When a file is
		//  first opened, initial setting for comment lines is Read.

	    void end_of_line_comments(const std::string & marker);
		//  Set the marker for end-of-line comments.  The marker is a
		//  special sequence of non-whitespace characters that marks
		//  the start of a comment that extends to the end of the line.
		//  The line's contents are those characters that preceed the
		//  comment.

	    void end_of_line_comments(Leave_or_Remove leave_or_remove);
		//  Determine what to do with end-of-line comments -- either
		//  leave them intact on lines when reading them from the file,
		//  or remove them before returning the lines with read_line().
		//  When a file is first opened, initial setting for end-of-line
		//  comments is Leave.

	    bool read_line(std::string & line);
		//  Reads a line from the text file.  Blank lines are skipped
		//  if blank_lines(Skip) has been called.  Similarly comment
		//  lines are skipped if comment_lines(Skip) has been called.
		//  Also if the line to be returned has an end-of-line comment,
		//  it will be removed if end_of_line_comments(Remove) has been
		//  called.
		//
		//  Return value:
		//    true    = A line was read.
		//    false   = The end of file was reached.
		//
		//  Throws File::Error exception if an error occurs while
		//  reading the file.

	    File::Error error(const Multi_Line_Text & message) const;
		//  Construct an File::Error object with the given message.
		//  The file's name and description are used to construct the
		//  object.  The location is either "at end of" if at_end()
		//  returns true or "at line # in " where # is line number
		//  returned by line_num().

	    //------------
	    //	Attributes

	    Read_or_Skip blank_lines() const;
		//  What is currently done with blank lines?

	    Read_or_Skip comment_lines() const;
		//  What is currently done with comment lines?

	    Leave_or_Remove end_of_line_comments() const;
		//  What is currently done with end-of-line comments?

	    int line_num() const;
		//  Returns the line number of the line returned by the most
		//  recent call to "read_line".

	    bool at_end() const;
		//  Returns true if at end of the file (no more lines to read);
		//  false otherwise.

	//---------------------------------------------------------------------

	private :
	    Read_or_Skip    blank_lines_;
	    Read_or_Skip    comment_lines_;
	    std::string	    comment_line_marker_;
	    Leave_or_Remove eol_comments_;
	    std::string	    eol_comment_marker_;
	    int		    line_num_;
	    bool	    eof_reached_;

	    std::ifstream   stream_;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "Input_Text_File.inl"

//-----------------------------------------------------------------------------

#endif
