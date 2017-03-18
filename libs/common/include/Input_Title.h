#ifndef COMMON_LIB__INPUT_TITLE_H
#define COMMON_LIB__INPUT_TITLE_H

//-----------------------------------------------------------------------------

#include <string>
#include <vector>

namespace Input
{
    class Text_File;
};

enum  Required_or_Optional;

//-----------------------------------------------------------------------------

//  Class:  Input::Title
//
//  This class represents the title of an Input_Text_File.  The title is a
//  single line with at least one non-whitespace character.

namespace Input
{
    //-------------------------------------------------------------------------

    class Title
    {
	public:
	    //------------
	    //  Operations

	    Title();
		//  Create a title.

	    bool read(Input::Text_File &   file,
		      Required_or_Optional reqd_or_opt);
		//  Read the title from an input text file.  If a title is
		//  successfully read, then the function returns {true}.  If
		//  the file is configured to _not_ skip blank lines, and a
		//  blank line is read, the title is considered missing.  The
		//  title is also considered missing if the end of the file is
		//  reached.  A required title that's missing results in a
		//  File::Error exception being thrown.  An optional title
		//  that's missing results in the function returning {false}.

	    bool matches(const std::string & str) const;
		//  Return {true} if the title matches the given string.  The
		//  matching is case-insensitive, and only words are compared.
		//  Words are separated by whitespace; therefore, the title
		//
		//	"  Some_application - It's parameter file"
		//
		//  matches this string:
		//
		//	"SOME_Application     -   it's  PARAmeter  file   "

	    void must_match(const std::string & str) const;
		//  If the title matches the string, then the function simply
		//  returns.  Otherwise, it throws a File::Error.

	    unsigned int must_match(const std::vector<std::string> & strs)
									const;
		//  If the title matches one of the strings, then the function
		//  returns the index of the matched string.  Otherwise, it
		//  throws a File::Error.

	private:
	    //----------------
	    //	Implementation

	    bool have_title_;
		//  Have we read a title from a file?

	    std::string	title_;
		//  The actual title read from a file.

	    std::string	canonical_title_;
		//  The title in its canonical form.

	    Input::Text_File * file_;
		//  The file from which the title was read from (or at least
		//  attempted to read from).
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
