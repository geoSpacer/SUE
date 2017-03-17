#include <sstream>

#include "info_as_str.h"
#include "Version_Number.h"

//-----------------------------------------------------------------------------

namespace
{

    std::string info_as_str(const std::string &	   name,
			    const Version_Number & version,
			    const char *	   build_date)
	//  Return the information about a program or library as a string in
	//  this format:
	//
	//	"{name} version #.# [release] - build_date"
    {
	std::ostringstream strm;
	strm << name << " version " << version.str() << " - "
	     << build_date;
	return strm.str();
    }

};

//-----------------------------------------------------------------------------

std::string prog_info_as_str(const char *	    name,
			     const Version_Number & version,
			     const char *	    build_date)
{
    return info_as_str(name, version, build_date);
}

//-----------------------------------------------------------------------------

std::string lib_info_as_str(const char *	   name,
			    const Version_Number & version,
			    const char *	   build_date)
{
    std::string lib_name(name);
    lib_name += " library,";
    return info_as_str(lib_name, version, build_date);
}
