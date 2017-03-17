#include <string>

#include "lib_info.h"
#include "info_as_str.h"
#include "Version_Number.h"
#include "build_date.h"

//----------------------------------------------------------------------------

std::string Common_Library::lib_info()
{
    static Version_Number version(2,0, Release_Candidate(1));

    return lib_info_as_str("Common", version, build_date);
}
