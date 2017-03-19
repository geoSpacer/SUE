//-----------------------------------------------------------------------------
//  Class implementation:  File::Path
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include "File_Path.h"
#include "Assert_That.h"

//-----------------------------------------------------------------------------

namespace
{
    //-------------------------------------------------------------------------

    const std::string delimiters("\\/");

    const char delimiter(delimiters[0]);

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

const bool File::Path::No_Extension   = false;
const bool File::Path::With_Extension = true;

//-----------------------------------------------------------------------------

std::string File::Path::basename(bool extension) const
{
    if (extension)
	return basename_ + ext_;
    else
	return basename_;
}

//-----------------------------------------------------------------------------

const std::string & File::Path::str() const
{
    if (! have_str_) {
	if (drive_ != "")
	    str_ = drive_ + ':';
	if (is_absolute())
	    str_ += delimiter;
	for (unsigned int pos = 0; pos < count(); ++pos) {
	    str_ += components_[pos];
	    if (pos < count() - 1)
		str_ += delimiter;
	}

	have_str_ = true;
    }

    return str_;
}

//-----------------------------------------------------------------------------

File::Path File::Path::parent() const
{
    std::vector<std::string> parent_components(components_);
    if (parent_components.size() > 0)
	parent_components.pop_back();

    return File::Path(drive_, is_absolute_, parent_components);
}

//-----------------------------------------------------------------------------

File::Path::Path(const std::string & path)
    : drive_(""),
      is_absolute_(false),
      components_(),
      have_str_(false),
      str_()
{
    std::string str(path);

    //	Look for drive letter.
    if (str.size() >= 2 && isalpha(str[0]) && str[1] == ':') {
	drive_ = str.substr(0, 1);
	str = str.substr(2);
    }

    //	Does the path start at the root directory?
    if (str.size() > 0 && delimiters.find(str[0]) != std::string::npos) {
	is_absolute_ = true;
	str = str.substr(1);
    }

    //	Separate out the components.
    while (str.size() > 0) {
	std::string::size_type next_delimiter = str.find_first_of(delimiters);
	std::string component = str.substr(0, next_delimiter);
	if (component != "")
	    components_.push_back(component);
	str = next_delimiter < str.size() ? str.substr(next_delimiter + 1)
					  : "";
    }

    set_basename_and_ext_();
}

//-----------------------------------------------------------------------------

File::Path::Path(const std::string &		  drive,
		 bool				  is_absolute,
		 const std::vector<std::string> & components)
    : drive_(drive),
      is_absolute_(is_absolute),
      components_(components),
      have_str_(false),
      str_()
{
    ASSERT_THAT( ((drive.size() == 1) && isalpha(drive[0])) || (drive == "") )

    for (unsigned int i = 0; i < components.size(); ++i) {
	const std::string & component = components[i];
	ASSERT_THAT(component != "")
    }

    set_basename_and_ext_();
}

//-----------------------------------------------------------------------------

const std::string & File::Path::operator[](unsigned int position) const
{
    ASSERT_THAT(position < count())
    return components_[position];
}

//-----------------------------------------------------------------------------

void File::Path::operator+=(const File::Path & path)
{
    ASSERT_THAT(path.drive() == "" && ! path.is_absolute())

    //	For each initial ".." in the given path, strip the last component of
    //	myself (only if that component is not "..").
    unsigned int pos;
    for (pos = 0; components_.size() > 0 && components_.back() != ".."
					 && pos < path.count()
					 && path[pos] == "..";
		  pos++) {
	components_.pop_back();
    }

    for (; pos < path.count(); pos++)
	components_.push_back(path[pos]);

    set_basename_and_ext_();

    have_str_ = false;
    str_ = "";
}

//-----------------------------------------------------------------------------

void File::Path::set_basename_and_ext_()
{
    unsigned int count = components_.size();
    if (count == 0) {
	basename_ = "";
	ext_ = "";
    }
    else {
	basename_ = components_.back();
	std::string::size_type period = basename_.find_first_of(".");
	if (period != std::string::npos) {
	    ext_ = basename_.substr(period);
	    basename_ = basename_.substr(0, period);
	}
    }
}
