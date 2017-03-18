#ifndef COMMON_LIB__FILE_STAT_H
#define COMMON_LIB__FILE_STAT_H

//-----------------------------------------------------------------------------

#include "File_Path.h"
#include "Date_Time.h"

//-----------------------------------------------------------------------------

//  Enum:  File_Type
//
//  This enumerated type represents various file types.

enum File_Type
{
    Not_Exist,
    Unknown,
    Regular_File,
    Directory
};

//-----------------------------------------------------------------------------

//  Class:  File::Stat
//
//  This class represents status information for a file.

namespace File
{

    class Stat
    {
	//------------
	//  Attributes

	public:

	    const Path & path() const;
		//  The path to the file.

	    File_Type type() const;
		//  The file's type.

	    const Date_Time & mod_time() const;
		//  The date-time the file was last modified.

	//------------
	//  Operations


	    static
	    Stat * get(const Path & path);
		//  Factory method to get the status object for a file.
		//  If the file does not exist, 0 is returned.  The caller
		//  is responsible for deleting the object.

	//-------------------------------------------------------------------------

	private:

	    Path path_;
	    File_Type type_;
	    Date_Time mod_time_;

	    Stat(const Path & path);
    };

};

//-----------------------------------------------------------------------------

#include "File_Stat.inl"

//-----------------------------------------------------------------------------

#endif
