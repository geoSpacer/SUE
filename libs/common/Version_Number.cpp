//#include "pragmas.h"

#include <sstream>

#include "Version_Number.h"
#include "Assert_That.h"

//----------------------------------------------------------------------------

Version_Number::Version_Number(unsigned int	    major_version_number,
			       unsigned int	    minor_version_number,
			       const Release_Type & release)
    : major_(major_version_number),
      minor_(minor_version_number),
      release_(release)
{
    ASSERT_THAT(major_version_number > 0 || minor_version_number > 0)
}

//----------------------------------------------------------------------------

std::string Version_Number::str() const
{
    std::ostringstream strm;
    strm << major_ << "." << minor_ << " (" << release_.str() << ")";
    return strm.str();
}
