#ifndef COMMON_LIB__STR_EQUAL_FUNC_H
#define COMMON_LIB__STR_EQUAL_FUNC_H

//-----------------------------------------------------------------------------

#include <string>

//-----------------------------------------------------------------------------

//  Typedef:  Str_Equal_Func
//
//  This typedef represents a function that tests for equality between two
//  strings.
//
//  Examples:	std::operator==
//		Ignore_Case::eq

typedef bool (*Str_Equal_Func)(const std::string &,
			       const std::string &);

//-----------------------------------------------------------------------------

#endif
