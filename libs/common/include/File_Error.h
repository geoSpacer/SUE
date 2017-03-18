#ifndef COMMON_LIB__FILE_ERROR_H
#define COMMON_LIB__FILE_ERROR_H

//-----------------------------------------------------------------------------

#include <string>
#include <iostream>

#include "File_Name_And_Desc.h"
#include "Error.h"

//-----------------------------------------------------------------------------

//  Class:  File::Error
//
//  This class represents an error associated with a file.

namespace File
{

    class Error
	: public Name_And_Desc,
	  public ::Error
    {
	public :
	    //------------
	    //	Operations

	    Error(const std::string &	  name,
		  const std::string &	  description,
		  const std::string &	  location,
		  const Multi_Line_Text & message);

	    Error(const Name_And_Desc &	  name_and_desc,
		  const std::string &	  location,
		  const Multi_Line_Text & message);

		//  Construct an object with the given file name and
		//  description.  The error occurred at the given {location}:
		//
		//	for text files, location = line # or EOF
		//	for binary files, location = a byte offset
		//
		//  The message describes the error.

	    //------------
	    //	Attributes

	    const std::string & location() const;
		//  The location in the file where the error occurred.

	//---------------------------------------------------------------------

	private :
	    std::string location_;
    };

};

//-----------------------------------------------------------------------------

//  This function prints a file error in the following format to an output
//  stream:
//
//	Error {location} the {description} file "{name}":
//	  {message's line 0}
//	  {message's line 1}
//	  ...
//
//  If {location} is "", then the word "with" is used instead.
//  If {message} has no lines, then the output is simply:
//
//	Error {location} the {description} file "{name}".

void print(const File::Error & error,
	   std::ostream &      strm);

//-----------------------------------------------------------------------------

//  Namespace "File_Error" contains the different types of file errors.

namespace File_Error
{
    //-------------------------------------------------------------------------

    //	Class:  File_Error::Cannot_Open
    //
    //	This class represents the error when a file cannot be opened.

    class Cannot_Open
	: public File::Error
    {
	public:
	    //------------
	    //	Operations

	    Cannot_Open(const std::string & name,
			const std::string & description);

	    Cannot_Open(const File::Name_And_Desc & name_and_desc);

		//  Construct a "can't open" file error with the given file
		//  name and description.
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#include "File_Error.inl"

//-----------------------------------------------------------------------------

#endif
