#include "pragmas.h"

#include <map>
#include <string>

#include "str_to_bool.h"
#include "Ignore_Case.h"
#include "Enum_assign.h"


//-----------------------------------------------------------------------------

bool str_to_bool(const std::string & str,
		 bool &		     value)
{
    static bool initialize = true;
    static std::map<std::string, bool, Ignore_Case> valid_strs;

    if (initialize) {
	valid_strs["yes"] = true;
	valid_strs["y"]	  = true;

	valid_strs["no"] = false;
	valid_strs["n"]	 = false;
	valid_strs["-"]	 = false;

	initialize = false;
    }

    return Enum::assign(value, str, valid_strs);
}
