#ifndef COMMON_LIB__RELEASE_TYPE_H
#define COMMON_LIB__RELEASE_TYPE_H

//-----------------------------------------------------------------------------

#include <string>

//-----------------------------------------------------------------------------

//  Class:  Release_Type
//
//  This class represents the types of releases for a version of a program or
//  library.  There are 3 types:
//
//	Beta
//	Release_Candidate
//	Official
//
//  There can be multiple beta releases and release candidates for a particular
//  version; therefore, these releases are numbered from 1 on.  Furthermore,
//  there may be different branches of development during prototyping, so a
//  beta release may have an associated branch name to distinguish it from
//  beta releases on other branches.  There is only one official release per
//  version, so this type of release has no associated number.

class Release_Type
{
    public:
	//  The following functions are provided to simplify the construction
	//  of a release type for a version number.  They're friends so they
	//  can access the class' private constructors.

	friend Release_Type Beta_Release(const char * name,
					 unsigned int number);

	friend Release_Type Beta_Release(unsigned int number);

	friend Release_Type Release_Candidate(unsigned int number);

	friend Release_Type Official_Release();

	//------------
	//  Attributes

	std::string str() const;
	    //	Return a string representation of the release type:
	    //
	    //	    {name} beta release {r#}
	    //	    beta release {r#}
	    //	    release candidate {r#}
	    //	    official release
	    //
	    //	where:	{name} is branch name
	    //		{r#}   is release number

    private:
	enum Types {
	    Beta,
	    Candidate,
	    Official
	};

	//------------
	//  Operations

	Release_Type(Types	  type,
		     unsigned int number);
	    //	Create a release type with a release number.

	Release_Type(const char * name,
		     unsigned int number);
	    //	Create a beta release with a branch name.

	Types	     type_;
	unsigned int number_;
	const char * name_;	//  branch name for a beta release
};

//-----------------------------------------------------------------------------

#endif
