#ifndef COMMON_LIB__VERSION_NUMBER_H
#define COMMON_LIB__VERSION_NUMBER_H

//-----------------------------------------------------------------------------

#include <string>

#include "Release_Type.h"

//-----------------------------------------------------------------------------

//  Class:  Version_Number
//
//  This class represents version numbers.  A version # has these components:
//
//	major number   =  an integer = or > 0
//	minor number   =  an integer = or > 0
//			  (both major and minor cannot be 0)
//
//  A version may have different types of releases, to reflect the different
//  stages of development for a version:
//
//	beta release	    = Experimental; exploring possible functionality
//			      for the version.  A beta release may have a
//			      name associated with it to denote the
//			      functionality being explored.
//
//	release candidate   = A candidate for the official release pending
//			      some final testing.
//
//	official release
//
//  There is only 1 official release per version; there may be multiple
//  releases of the other types (beta, release candidate).  Therefore, those
//  releases have an associated release number (an integer = or > 1).
//
//  The following functions are provided to specify a release type when
//  defining a version number:
//
//	Release_Type Beta_Release(const char * name,
//				  unsigned int number);
//
//	Release_Type Beta_Release(unsigned int number);
//
//	Release_Type Release_Candidate(unsigned int number);
//
//	Release_Type Official_Release();

class Version_Number {
    public :
	//------------
	//  Operations

	Version_Number(unsigned int	    major,
		       unsigned int	    minor,
		       const Release_Type & release);
	    //	Create a version number with the given major number, minor
	    //	number, and release type.

	//------------
	//  Attributes

	unsigned int major() const;
	    //	Return the major number.

	unsigned int minor() const;
	    //	Return the minor number.

	std::string str() const;
	    //	Return a string representation of the version number and
	    //	release type:
	    //
	    //	    {M#}.{m#} ({name} beta release {r#})
	    //	    {M#}.{m#} (beta release {r#})
	    //	    {M#}.{m#} (release candidate {r#})
	    //	    {M#}.{m#} (official release)
	    //
	    //	where:	{M#}   is major number
	    //		{m#}   is minor number
	    //		{name} is prototype's associated name
	    //		{r#}   is release number

    private:
	unsigned int major_;
	unsigned int minor_;
	Release_Type release_;
};

//-----------------------------------------------------------------------------

#include "Version_Number.inl"

//-----------------------------------------------------------------------------

#endif
