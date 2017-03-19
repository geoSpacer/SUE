//-----------------------------------------------------------------------------
//  Class implementation:  Output::Title
//-----------------------------------------------------------------------------

#include "Output_Title.h"
#include "trim_whitespace.h"

//-----------------------------------------------------------------------------

Output::Title::Title(const std::string & str)
    : str_(trim_whitespace(str))
{
}

//-----------------------------------------------------------------------------

void Output::Title::write(std::ofstream & file) const
{
    file << str_ << "\n";
}
