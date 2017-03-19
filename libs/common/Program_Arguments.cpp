#include "pragmas.h"

#include <sstream>

#include "Program_Arguments.h"
#include "Assert_That.h"

//-----------------------------------------------------------------------------

Error Program_Arguments::error(const Multi_Line_Text & message)
{
    std::string indent("  ");
    Multi_Line_Text new_mesg("The program's arguments have an error:");

    for (int i = 0; i < message.line_count(); i++)
	new_mesg += indent + message.line(i);

    return Error(new_mesg);
}

//-----------------------------------------------------------------------------

Error Program_Arguments::error(const std::string &     argument,
			       const std::string &     text,
			       unsigned int	       text_position,
			       const Multi_Line_Text & message)
{
    std::string indent("  ");
    Multi_Line_Text new_mesg("The program's arguments have an error:");

    new_mesg += indent + "Argument = \"" + argument + "\"";
    std::string line;
    line = indent + "Error ------";
    int i;
    for (i = text_position; i > 0; i--)
	line += '-';
    for (i = text.size() - 1; i > 0; i--)
	line += '^';
    line += '^';
    new_mesg += line;

    for (i = 0; i < message.line_count(); i++)
	new_mesg += indent + message.line(i);

    return Error(new_mesg);
}

//-----------------------------------------------------------------------------

std::string Program_Arguments::extra_found(unsigned int extra_count,
					   int		argc,
					   char *	argv[])
{
    ASSERT_THAT(extra_count > 0 && extra_count < (unsigned int) argc)
	//  Note: the above conditional is not "extra_count <= argc" because
	//  minimally the program is passed the name it was invoked by, i.e.,
	//  argv[0].

    std::ostringstream mesg;
    mesg << "Extra argument" << (extra_count > 1 ? "s" : "") << " found: \""
	    << argv[argc - extra_count] << "\""
	    << (extra_count > 1 ? " ..." : "" ) ;
    return mesg.str();
}
