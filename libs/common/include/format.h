#ifndef COMMON_LIB__FORMAT_H
#define COMMON_LIB__FORMAT_H

//-----------------------------------------------------------------------------

#include "numeric_formats.h"

//-----------------------------------------------------------------------------

//  Function: format
//
//  This function formats a number according to a given format specification
//  and returns a string representation of the number.
//
//  Note:  This function is provided to aid the transition of older to this
//	   version of the library.  It is recommended that new code should
//	   use the operator() of the numeric format classes, or the
//	   corresponding operator<<, e.g.,
//
//		int i;
//		std::cout << Int_Fmt('+',3)(i);
//
//		float f;
//		std::cout << ( Fix_Fmt('+',leading_0s,5,2) << f );

//-----------------------------------------------------------------------------

//  Variations for integers

std::string format(long		   i,
		   const Int_Fmt & fmt = Int_Fmt::default_format);

std::string format(int		   i,
		   const Int_Fmt & fmt = Int_Fmt::default_format);

std::string format(unsigned long   i,
		   const Int_Fmt & fmt = Int_Fmt::default_format);

std::string format(unsigned int	   i,
		   const Int_Fmt & fmt = Int_Fmt::default_format);

//-----------------------------------------------------------------------------

//  Variation for floating-point numbers

std::string format(double		d,
		   const Float_Format & fmt);

std::string format(double	   d,
		   const Fix_Fmt & fix_fmt,
		   const Sci_Fmt & sci_fmt);
    //	The original version for doing general format.

//-----------------------------------------------------------------------------

#include "format.inl"

//-----------------------------------------------------------------------------

#endif
