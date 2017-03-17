//-----------------------------------------------------------------------------
//  Class implementation:  Output::File
//-----------------------------------------------------------------------------

#include "pragmas.h"

#include "Output_File.h"
#include "File_Type.h"
#include "File_Path.h"
#include "make_dir.h"
#include "File_Error.h"

//-----------------------------------------------------------------------------

Output::File::File()
{
}

//-----------------------------------------------------------------------------

void Output::File::open(const std::string & name,
			const std::string & description)
{
    if (is_open())
	close();

    if (get_file_type(name) == Directory)
	throw ::File::Error(name, description, "",
			    "A directory with that name already exists.");

    ::File::Path path(name);
    std::string dir = path.parent().str();
    if (dir != "") {
	try {
	    if (! make_dir(dir))
		throw ::File::Error(name, description, "",
				    "Could not make the directory \"" + dir
								      + "\".");
	}
	catch (::File::Error & e) {
	    throw ::File::Error(name, description, "", e.message());
	}
    }

    BaseClass::open(name.c_str());
}

//-----------------------------------------------------------------------------

Output::File::~File()
{
    if (is_open())
	close();
}
