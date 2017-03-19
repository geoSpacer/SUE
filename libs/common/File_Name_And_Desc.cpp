//-----------------------------------------------------------------------------
//  Class implementation:  File::Name_And_Desc
//-----------------------------------------------------------------------------

#include "File_Name_And_Desc.h"
#include "Assert_That.h"

//-----------------------------------------------------------------------------

File::Name_And_Desc::Name_And_Desc(const std::string & name,
				   const std::string & description)
    : name_(name),
      desc_(description)
{
    ASSERT_THAT(name != "")
}
