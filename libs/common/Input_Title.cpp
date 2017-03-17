//-----------------------------------------------------------------------------
//  Class implementation:  Input::Title
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include <string>
#include <cctype>
#include <sstream>

#include "Input_Title.h"
#include "Input_Text_File.h"
#include "Required_or_Optional.h"
#include "trim_whitespace.h"
#include "Assert_That.h"
#include "Ignore_Case.h"

//-----------------------------------------------------------------------------

Input::Title::Title()
    : have_title_(false),
      title_(""),
      canonical_title_(""),
      file_(0)
{
}

//-----------------------------------------------------------------------------

namespace
{
    //-------------------------------------------------------------------------

    std::string canonical_form(const std::string & title)
	//  Return the canonical form of a title.  The canonical form has
	//  leading and trailing whitespace removed, and each internal
	//  sequence of whitespace characters is replaced by a single space.
    {
	std::string::size_type start = std::string::npos;
	    //  The start of the current whitespace sequence.
	int length;
	    //  The length of the current whitespace sequence.

	std::string str = trim_whitespace(title);

	std::string::size_type i;
	for (i = 0; i < str.size(); i++) {
	    if (isspace(str[i])) {
		if (start == std::string::npos) {
		    start = i;
		    length = 1;
		} else {
		    length++;
		}
	    } else {
		if (start != std::string::npos) {
		    //  If we just finished a whitespace sequence, then replace
		    //  it with a single space.
		    str.replace(start, length, " ");
		    i = start + 1;
		    start = std::string::npos;
		}
	    }
	}

	return str;
    }

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

bool Input::Title::read(Input::Text_File &   file,
			Required_or_Optional reqd_or_opt)
{
    have_title_ = false;

    file_ = &file;
    std::string line;
    if (file.at_end() || ! file.read_line(line)) {
	if ((bool) reqd_or_opt == (bool) Required)
	    throw file.error("Expected a title, but found none.");
	else
	    return false;
    }

    line = trim_whitespace(line);
    if (line == "") {
	if ((bool) reqd_or_opt == (bool) Required)
	    throw file.error("Expected a title, but found none.");
	else
	    return false;
    }

    title_ = line;
    canonical_title_ = canonical_form(title_);
    have_title_ = true;

    return true;
}

//-----------------------------------------------------------------------------

bool Input::Title::matches(const std::string & str) const
{
    ASSERT_THAT(have_title_)
    return Ignore_Case::eq(canonical_title_, canonical_form(str));
}

//-----------------------------------------------------------------------------

void Input::Title::must_match(const std::string & str) const
{
    if (! matches(str)) {
	std::ostringstream mesg;
	mesg << "Expected this title:\n"
		"\n"
	     << "  " << str << "\n"
	        "\n"
	        "but found this title instead:\n"
	        "\n"
	     << "  " << title_ << "\n";
	throw file_->error(mesg);
    }
}

//-----------------------------------------------------------------------------

unsigned int Input::Title::must_match(const std::vector<std::string> & strs)
									const
{
    ASSERT_THAT(strs.size() > 0)

    for (unsigned int i = 0; i < strs.size(); i++)
	if (matches(strs[i]))
	    return i;

    std::ostringstream mesg;
    mesg << (strs.size() == 1 ? "Expected this title:\n"
			      : "Expected one of these titles:\n")
	 << "\n";
    for (unsigned int j = 0; j < strs.size(); j++)
	mesg << "  " << strs[j] << "\n";

    mesg << "\n"
	    "but found this title instead:\n"
	    "\n"
	 << "  " << title_ << "\n";
    throw file_->error(mesg);
}
