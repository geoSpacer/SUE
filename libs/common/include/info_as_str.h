#ifndef COMMON_LIB__INFO_AS_STR_H
#define COMMON_LIB__INFO_AS_STR_H

//-----------------------------------------------------------------------------

#include <string>

class Version_Number;

//-----------------------------------------------------------------------------

std::string prog_info_as_str(const char *	    name,
			     const Version_Number & version,
			     const char *	    build_date);
    //  This function returns the information about a program (its name,
    //	version number and build date) as a string in this format:
    //
    //	    "{name} version #.# [release] - date"

std::string lib_info_as_str(const char *	   name,
			    const Version_Number & version,
			    const char *	   build_date);
    //  This function returns the information about a library (its name,
    //	version number and build date) as a string in this format:
    //
    //	    "{name} library, version #.# [release] - date"

//-----------------------------------------------------------------------------

#endif
