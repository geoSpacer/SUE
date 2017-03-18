#ifndef COMMON_LIB__MIN_MAX_H
#define COMMON_LIB__MIN_MAX_H

//-----------------------------------------------------------------------------

#ifndef _WIN32

#include <algorithm>

#else

namespace std
{
    //-------------------------------------------------------------------------
    //  Note:   Visual C++ 6.00 does not have the template functions min() and
    //		max() defined in the standard header file <algorithm>.  The
    //		templates below are from pg 544 of Stroustrup's "C++ Language"
    //		book, 3rd edition.

    //-------------------------------------------------------------------------

 //   template<class T>
 //   const T & max(const T & a,
	//	  const T & b)
 //   {
	//return (a < b) ? b : a;
 //   }

    //-------------------------------------------------------------------------

 //   template<class T,
	//     class Cmp>
 //   const T & max(const T & a,
	//	  const T & b,
	//	  Cmp	    cmp)
 //   {
	//return (cmp(a, b)) ? b : a;
 //   }

    //-------------------------------------------------------------------------

 //   template<class T>
 //   const T & min(const T & a,
	//	  const T & b)
 //   {
	//return (b < a) ? b : a;
 //   }

    //-------------------------------------------------------------------------

 //   template<class T,
	//     class Cmp>
 //   const T & min(const T & a,
	//	  const T & b,
	//	  Cmp	    cmp)
 //   {
	//return (cmp(b, a)) ? b : a;
 //   }

    //-------------------------------------------------------------------------
};

#endif	//  #else part of #ifndef _WIN32

//-----------------------------------------------------------------------------

#endif
