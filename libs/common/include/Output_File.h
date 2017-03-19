#ifndef COMMON_LIB__OUTPUT_FILE_H
#define COMMON_LIB__OUTPUT_FILE_H

//-----------------------------------------------------------------------------

#include <fstream>

namespace File
{
    class Error;
};

//-----------------------------------------------------------------------------

//  Class:  Output::File
//
//  This class represents an output file.  It's a derivation of std::ofstream
//  which will create any intermediate directories when opening the file.

namespace Output
{
    //-------------------------------------------------------------------------

    class File
	: public std::ofstream
    {
	public:
	    //------------
	    //	Operations

	    File();
		//  Create an unopened file.

	    void open(const std::string & name,
		      const std::string & description = "")
		      throw (::File::Error);
		//  Open the named file.  {description} is a brief description
		//  of the file's contents.  If it's a new file, any missing
		//  intermediate directories are also created.  If the file
		//  cannot be opened, a File::Error exception is thrown.

	    virtual
	    ~File();
		//  Close the file (if open).

	//---------------------------------------------------------------------

	private:
	    //	Hide the inherited open(...) member.
	    void open(const char *	      name,
		      std::ios_base::openmode mode);

	    //	Our "open" operation uses the inherited one; however, Visual
	    //	C++ has a bug that prevents us from referencing it.  See the
	    //	Knowledge Base article "BUG: Access to Nested Base Class
	    //	Member Functions Blocked" (Article ID: Q167749).  The typedef
	    //	below is a suggested workaround.

	    typedef std::ofstream BaseClass;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
