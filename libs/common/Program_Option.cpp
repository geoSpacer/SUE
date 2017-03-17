//-----------------------------------------------------------------------------
//  Class implementation:  Program_Option
//-----------------------------------------------------------------------------

#include "Program_Option.h"
#include "Assert_That.h"

//-----------------------------------------------------------------------------

Program_Option::Program_Option(const std::string &  option_name,
			       unsigned int	    id_,
			       Required_or_Optional reqd_or_opt_,
			       Value_Status	    value_status_)
    : name(option_name),
      id(id_),
      reqd_or_opt(reqd_or_opt_),
      value_status(value_status_)
{
    ASSERT_THAT(option_name != "")
}
