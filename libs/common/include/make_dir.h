#ifndef COMMON_LIB__MAKE_DIR_H
#define COMMON_LIB__MAKE_DIR_H

//-----------------------------------------------------------------------------

#include <string>

namespace File
{
    class Error;
};

//-----------------------------------------------------------------------------

bool make_dir(const std::string & path)
	    throw (File::Error);
    //	Make a directory.  Any of the intermediate directories in the path
    //	(i.e., ancestors of the specified directory) that do not exist are
    //	also made.  For example, if the path is "abc/def/ghi", and "abc" does
    //	not exist, then "abc", "abc/def", and "abc/def/ghi" are all made.
    //
    //	If an intermediate "directory" already exists, but is not a directory
    //	then a File::Error exception is thrown.  In the above example, if
    //	"abc/def" was a file, then an exception is thrown.
    //
    //	{true} is returned if the directory already exists or was made.
    //	{false} is returned if the path is incorrect or the directory was not
    //	made.

//-----------------------------------------------------------------------------

#endif
