#ifndef COMMON_LIB__OUTPUT_TITLE_H
#define COMMON_LIB__OUTPUT_TITLE_H

//-----------------------------------------------------------------------------

#include <string>
#include <fstream>

//-----------------------------------------------------------------------------

//  Class:  Output::Title
//
//  This class represents the title for an output text file.

namespace Output
{
    //-------------------------------------------------------------------------

    class Title {
	public:
	    //------------
	    //	Operations

	    Title(const std::string & str);
		//  Construct a title with the given string.

	    void write(std::ofstream & file) const;
		//  Write the title to a file.

	private:
	    //----------------
	    //	Implementation

	    std::string str_;
    };

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
