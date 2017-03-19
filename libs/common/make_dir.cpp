#include "pragmas.h"

#include <string>

#ifdef WIN32
    #include <direct.h>
#endif

#include "make_dir.h"
#include "File_Path.h"
#include "File_Type.h"
#include "File_Error.h"

//-----------------------------------------------------------------------------

bool make_dir(const std::string & path)
{
    File::Path file_path(path);
    if (file_path.str() == "")
	return false;

    switch (get_file_type(path)) {
	case Regular_File:
	case Unknown:
	    throw File::Error(path, "", "", path + " is not a directory.");

	case Directory:
	    return true;

	default:    //	Not_Exist
	    break;
    }


    std::string parent_dir = file_path.parent().str();
    if (parent_dir != "" && get_file_type(parent_dir) == Not_Exist) {
	if (! make_dir(parent_dir))
	    return false;
    }

    if (file_path.count() > 0) {
#ifdef WIN32
	if (_mkdir(file_path.str().c_str()))
	    return false;
#else
	#error	This function is not implemented on this platform.
#endif
    }

    return true;
}
