//-----------------------------------------------------------------------------
//  Class implementation:  Input_Value::Line
//-----------------------------------------------------------------------------

#include "../pragmas.h"

#include "Input_Value_Line.h"
#include "Input_Text_File.h"
#include "Assert_That.h"

//----------------------------------------------------------------------------

Input_Value::Line::Line()
    : str_(""),
      name_(""),
      name_pos_(0),
      unmatched_()
{
}

//----------------------------------------------------------------------------

bool Input_Value::Line::name_matches(const std::string & name,
				     Str_Equal_Func      str_equal_func,
				     std::string &	 rest_of_line)
{
    ASSERT_THAT(str_equal_func != 0)

    if (str_equal_func(name, name_)) {
	rest_of_line = str_.substr(name_pos_ + name_.size());
	return true;
    } else {
	unmatched_.push_back(name);
	return false;
    }
}

//----------------------------------------------------------------------------

bool Input_Value::Line::read(Input::Text_File & file)
{
    if (file.read_line(str_)) {
	std::istringstream strm(str_);
	if (strm >> name_) {
	    name_pos_ = str_.find(name_);
	} else {
	    name_ = "";
	    name_pos_ = 0;
	}
	unmatched_.clear();
	return true;
    } else {
	str_ = "";
	name_ = "";
	name_pos_ = 0;
	return false;
    }
}
