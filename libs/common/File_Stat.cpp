//-----------------------------------------------------------------------------
//  Class implementation:  File::Stat
//-----------------------------------------------------------------------------

#include "pragmas.h"

#ifdef WIN32
  #include <sys/types.h>
  #include <sys/stat.h>
#endif

#include <string>
#include <ctime>

#include "File_Stat.h"

#include "Assert_That.h"

//-----------------------------------------------------------------------------

File::Stat * File::Stat::get(const File::Path & path)
{
    File::Stat * stat = new Stat(path);
    if (stat && stat->type() == Not_Exist) {
	delete stat;
	return 0;
    }
    return stat;
}

//-----------------------------------------------------------------------------

File::Stat::Stat(const File::Path & path)
    : path_(path),
      type_(Not_Exist),
      mod_time_(Date(0, Jan, 1), Time_Of_Day(0, 0, 0))
{
    ASSERT_THAT(path.str() != "")

#ifdef WIN32

    std::string path_to_stat = path.str();

    //	_stat will fail for a path that is just a drive letter and colon,
    //	e.g., "C:".  But such a path is refering to the current directory
    //	on the drive, e.g., "C:."
    if (path.drive() != "" && path.str().size() == 2)
	path_to_stat += "." ;

    //	Note:  
    //	Windows can handle a trailing path delimiter if it's a '/', but not
    //	if it's a '\'.	For example, if there is a directory named "foo",
    //	then _stat will succeed for "foo/", but fail for "foo\".
    struct _stat stat_buf;
    if (! _stat(path_to_stat.c_str(), &stat_buf)) {
	if (stat_buf.st_mode & _S_IFREG)
	    type_ = Regular_File;
	else if (stat_buf.st_mode & _S_IFDIR)
	    type_ = Directory;
	else
	    type_ = Unknown;

	struct tm * mtime = localtime(&(stat_buf.st_mtime));
	mod_time_ = Date_Time(Date(mtime->tm_year + 1900,
				   Month(mtime->tm_mon + 1),
				   mtime->tm_mday),
			      Time_Of_Day(mtime->tm_hour,
					  mtime->tm_min,
					  (float) mtime->tm_sec));
    }

#else

    #error The class "File_Stat" isn't implemented for this platform.

#endif

}
