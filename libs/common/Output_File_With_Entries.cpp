//-----------------------------------------------------------------------------
//  Class implementation:  Output::File_With_Entries
//-----------------------------------------------------------------------------

#include <vector>
#include <algorithm>

#include "Output_File_With_Entries.h"
#include "void_mem_fun.h"

//-----------------------------------------------------------------------------

Output::File_With_Entries::File_With_Entries()
    : File()
{
}

//-----------------------------------------------------------------------------

void Output::File_With_Entries::write_entries(
			    std::vector<Output::File_With_Entries *> files)
{
    std::for_each(files.begin(), files.end(),
	void_mem_fun(&Output::File_With_Entries::write_entry));
}
