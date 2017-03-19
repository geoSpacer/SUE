//-----------------------------------------------------------------------------
//  Class implementation:  Input::Text_File
//-----------------------------------------------------------------------------

#include "../pragmas.h"

#include "Input_Text_File.h"
#include "Assert_That.h"
#include "has_whitespace.h"

//-----------------------------------------------------------------------------

const char * Default::Comment_Markers::whole_line  = ">";
const char * Default::Comment_Markers::end_of_line = "<<";

//-----------------------------------------------------------------------------

Input::Text_File::Text_File(const std::string & name,
			    const std::string & description)
    : File::Name_And_Desc(name, description),
      blank_lines_(Read),
      comment_lines_(Read),
      comment_line_marker_(Default::Comment_Markers::whole_line),
      eol_comments_(Leave),
      eol_comment_marker_(Default::Comment_Markers::end_of_line),
      line_num_(0),
      eof_reached_(false)
{
    stream_.open(name.c_str());
    if (! stream_)
	throw File_Error::Cannot_Open(*this);
}

//-----------------------------------------------------------------------------

void Input::Text_File::comment_lines(const std::string & comment_marker)
{
    ASSERT_THAT(comment_marker != "")
    ASSERT_THAT(! has_whitespace(comment_marker))
    comment_line_marker_ = comment_marker;
}

//-----------------------------------------------------------------------------

void Input::Text_File::end_of_line_comments(const std::string & comment_marker)
{
    ASSERT_THAT(comment_marker != "")
    ASSERT_THAT(! has_whitespace(comment_marker))
    eol_comment_marker_ = comment_marker;
}

//-----------------------------------------------------------------------------

namespace
{
    //-------------------------------------------------------------------------

    inline
    bool has_marker(const std::string & line,
		    int			position,
		    const std::string & marker)
	//  Determine if a line has a comment marker at a certain position.
    {
	return line.substr(position, marker.size()) == marker;
    }

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

bool Input::Text_File::read_line(std::string & line)
{
    if (eof_reached_)
	return false;
    if (stream_.eof()) {
	eof_reached_ = true;
	return false;
    }

    while (std::getline(stream_, line)) {
	line_num_++;

	if (blank_lines_ == (bool) Skip || comment_lines_ == (bool) Skip) {
	    //	So, we're skipping either blank lines or comment lines;
	    //	therefore, skip the initial whitespace on the line.
	    unsigned int i;
	    for (i = 0; i < line.size() && isspace(line[i]); i++)
		;  // empty loop body

	    if (i >= line.size()) {
		//  We have a blank line.  Are we skipping them?
		if (blank_lines_ == (bool) Skip)
		    //	go to next iteration of "while" loop to read next line
		    continue;
	    } else {
		//  We've encountered a non-whitespace character, i.e., it's a
		//  non-blank line.  If we're skipping comment lines, check to
		//  see if we have the associated marker.
		if (comment_lines_ == (bool) Skip && has_marker(line, i,
							 comment_line_marker_))
		    //	go to next iteration of "while" loop to read next line
		    continue;

		//  If we're skipping blank lines AND removing end-of-line
		//  comments, check to see if we have that marker.
		if (blank_lines_ == (bool) Skip && eol_comments_ == (bool) Remove
					 && has_marker(line, i,
						       eol_comment_marker_))
		    //	go to next iteration of "while" loop to read next line
		    continue;
	    }
	}

	//  We've got a line to return.	 Now check to see if we should remove
	//  end-of-line comments.
	if (eol_comments_ == (bool) Remove) {
	    std::string::size_type pos = line.find(eol_comment_marker_);
	    if (pos != std::string::npos)
		line = line.substr(0, pos);
	}

	return true;
    }

    //	getline() failed, so was it due to end-of-file found or an error?
    if (stream_.eof())
	eof_reached_ = true;
    else {
	//  Advance line # since that's the line we were trying to read.
	line_num_++;
	throw error("Could not read file (the function \"getLine\" failed).");
    }

    return false;
}

//-----------------------------------------------------------------------------

File::Error Input::Text_File::error(const Multi_Line_Text & message) const
{
    std::ostringstream location;
    if (eof_reached_)
	location << "at end of";
    else
	location << "at line " << line_num_ << " in";
    return File::Error(*this, location.str(), message);
}
