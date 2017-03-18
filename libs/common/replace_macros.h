#ifndef COMMON_LIB__REPLACE_MACROS_H
#define COMMON_LIB__REPLACE_MACROS_H

//-----------------------------------------------------------------------------

#include <string>
#include <map>

#include "Ignore_Case.h"
#include "Leave_or_Remove.h"

//-----------------------------------------------------------------------------

typedef std::map<std::string, std::string, Ignore_Case> Macro_Definitions;
    //	Map of macro names into their definitions (values).

std::string replace_macros(const std::string &	     str,
			   const Macro_Definitions & macros,
			   Leave_or_Remove           undefined = Remove);
    //	Replace the macros in a string with their definitions.  A macro's
    //	name is surrounded by braces, e.g., "{name}".  In order to have a
    //	left brace not interpreted as the start of a macro name, place a
    //	caret ("^") in front of the brace, i.e., "^{".  The third parameter
    //	"undefined" determines how undefined macros: either leave them in
    //	the string or remove them (as though their definitions were "").

//-----------------------------------------------------------------------------

#endif
