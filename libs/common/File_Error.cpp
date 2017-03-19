//-----------------------------------------------------------------------------
//  Class implementation:  File::Error
//			   File_Error::Cannot_Open
//
//  Function implemenation: "print"
//-----------------------------------------------------------------------------

#include "../pragmas.h"

#include "File_Error.h"

//-----------------------------------------------------------------------------
//  File::Error class
//-----------------------------------------------------------------------------

File::Error::Error(const std::string &	   name,
		   const std::string &	   description,
		   const std::string &	   location,
		   const Multi_Line_Text & message)
    : Name_And_Desc(name, description),
      ::Error(message),
      location_(location)
{
}

//-----------------------------------------------------------------------------

File::Error::Error(const Name_And_Desc &   name_and_desc,
		   const std::string &	   location,
		   const Multi_Line_Text & message)
    : Name_And_Desc(name_and_desc),
      ::Error(message),
      location_(location)
{
}

//-----------------------------------------------------------------------------
//  "print" function
//-----------------------------------------------------------------------------

void print(const File::Error & error,
	   std::ostream &      strm)
{
    strm << "Error ";
    if (error.location() != "")
	strm << error.location() << " ";
    else
	strm << "with ";
    strm << "the ";
    if (error.description() != "")
	strm << error.description() << " ";
    strm << "file \"" << error.name() << "\"";

    if (error.message().line_count() == 0)
	strm << ".\n";
    else {
	strm << ":\n";
	for (int i = 0; i < error.message().line_count(); ++i)
	    strm << "  " << error.message().line(i) << "\n";
    }
}

//-----------------------------------------------------------------------------
//  File_Error::Cannot_Open class
//-----------------------------------------------------------------------------

namespace
{
    const char * cannot_open_mesg = "Cannot open the file.";
}

//-----------------------------------------------------------------------------

File_Error::Cannot_Open::Cannot_Open(const std::string & name,
				     const std::string & description)
    : File::Error(name, description, "", cannot_open_mesg)
{
}

//-----------------------------------------------------------------------------

File_Error::Cannot_Open::Cannot_Open(const File::Name_And_Desc & name_and_desc)
    : File::Error(name_and_desc, "", cannot_open_mesg)
{
}
