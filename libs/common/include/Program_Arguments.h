#ifndef COMMON_LIB__PROGRAM_ARGUMENTS_H
#define COMMON_LIB__PROGRAM_ARGUMENTS_H

//-----------------------------------------------------------------------------

#include <string>

#include "Error.h"
#include "Multi_Line_Text.h"

//-----------------------------------------------------------------------------

namespace Program_Arguments
{
    //-------------------------------------------------------------------------

    Error error(const Multi_Line_Text & message);
	//  Construct an Error object with a message about the program's
	//  arguments:
	//
	//	The program's arguments have an error:
	//	  {message line 1}
	//	  {   "      "  2}
	//	  ...

    //-------------------------------------------------------------------------

    Error error(const std::string &	argument,
		const std::string &	text,
		unsigned int		text_position,
		const Multi_Line_Text & message);
	//  Construct an Error object with a message about the given program
	//  argument.  {text} is the text the problem within the argument,
	//  {text_position} is the starting position of this text.  The
	//  error message looks like this:
	//
	//	The program's arguments have an error:
	//	  Argument = "...       "
	//	  Error -----------^^^
	//	  {message line 1}
	//	  {   "      "  2}
	//	  ...

    //-------------------------------------------------------------------------

    std::string extra_found(unsigned int extra_count,
			    int		 argc,
			    char *	 argv[]);
	//  Construct a message that extra argument(s) were found.
	//  {extra_count} is the number of extra arguments; they are the _end_
	//  of the argument list {argv} which has {argc} arguments in it.

    //-------------------------------------------------------------------------
};

//-----------------------------------------------------------------------------

#endif
