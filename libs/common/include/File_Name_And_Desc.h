#ifndef COMMON_LIB__FILE_NAME_AND_DESC_H
#define COMMON_LIB__FILE_NAME_AND_DESC_H

//-----------------------------------------------------------------------------

#include <string>

//-----------------------------------------------------------------------------

//  Class:  File::Name_And_Desc
//
//  This class represents a file's name and description.  The description
//  consists of a few words, e.g., "input", "input data", "output binary", etc.

namespace File
{

    class Name_And_Desc
    {
	public :
	    //------------
	    //	Operations

	    Name_And_Desc(const std::string & name,
			  const std::string & description);
		//  Construct an object with the given file name and
		//  description.

	    //------------
	    //	Attributes

	    const std::string & name() const;
		//  The file's name.

	    const std::string & description() const;
		//  The file's description.

	private :
	    std::string name_;
	    std::string desc_;
    };

};

//-----------------------------------------------------------------------------

#include "File_Name_And_Desc.inl"

//-----------------------------------------------------------------------------

#endif
