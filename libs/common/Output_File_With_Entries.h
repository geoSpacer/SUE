#ifndef COMMON_LIB__OUTPUT_FILE_WITH_ENTRIES_H
#define COMMON_LIB__OUTPUT_FILE_WITH_ENTRIES_H

//-----------------------------------------------------------------------------

#include <vector>

#include "Output_File.h"

//-----------------------------------------------------------------------------

//  Class:  Output::File_With_Entries
//
//  This abstract class represents an Output::File which will have a sequence
//  of entries written to it.  Example: a text file that has a table of data,
//  and each row is an entry.

namespace Output
{
    //-------------------------------------------------------------------------

    class File_With_Entries
	: public File
    {
	public:
	    //------------
	    //  Operations

	    File_With_Entries();
		//  Create an unopened file.

	    virtual
	    void write_entry() = 0;
		//  Write a single entry into the output file.

	    virtual
	    ~File_With_Entries();
		//  Close the file.

	    static
	    void write_entries(std::vector<Output::File_With_Entries *> files);
		//  Write a single entry into each of the given files.
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "Output_File_With_Entries.inl"

//-----------------------------------------------------------------------------

#endif
