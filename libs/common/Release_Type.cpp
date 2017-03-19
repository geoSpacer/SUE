//-----------------------------------------------------------------------------
//  Class implementation:  Release_Type
//-----------------------------------------------------------------------------

#include <string>
#include <sstream>

#include "Release_Type.h"
#include "Assert_That.h"

//-----------------------------------------------------------------------------

Release_Type::Release_Type(Types	type,
			   unsigned int release_number)
    : type_(type),
      number_(release_number),
      name_(0)
{
    if (type != Official)
	ASSERT_THAT(release_number >= 1)
}

//-----------------------------------------------------------------------------

Release_Type::Release_Type(const char * name,
			   unsigned int release_number)
    : type_(Beta),
      number_(release_number),
      name_(name)
{
    ASSERT_THAT(release_number >= 1)
}

//-----------------------------------------------------------------------------

std::string Release_Type::str() const
{
    static const char * type_names[] = {
	"beta release",
	"release candidate",
	"official release"
    };

    std::ostringstream strm;
    if (name_ != 0)
	strm << name_ << " ";
    strm << type_names[type_];
    if (type_ != Official)
	strm << " " << number_;
    return strm.str();
}

//-----------------------------------------------------------------------------

//  Friend functions that are used to construct release types when constructing
//  a version number.

//-----------------------------------------------------------------------------

Release_Type Beta_Release(const char * name,
			  unsigned int number)
{
    return Release_Type(name, number);
}

//-----------------------------------------------------------------------------

Release_Type Beta_Release(unsigned int number)
{
    return Release_Type(Release_Type::Beta, number);
}

//-----------------------------------------------------------------------------

Release_Type Release_Candidate(unsigned int number)
{
    return Release_Type(Release_Type::Candidate, number);
}

//-----------------------------------------------------------------------------

Release_Type Official_Release()
{
    return Release_Type(Release_Type::Official, 0);
}
