#ifndef COMMAND_H
#define COMMAND_H

//-----------------------------------------------------------------------------

#include <string>
#include "Command_Code.h"

//-----------------------------------------------------------------------------


class Command
{
    public:
	Command(Command_Code code);
	    //	Constructs a command with no accompanying value.

	Command(Command_Code code,
	        int	     value);
	    //	Constructs a command with an integer value.

	Command(Command_Code code,
	        double	     value);
	    //	Constructs a command with a float value.

	Command(Command_Code	    code,
		const std::string & str);
	    //  Constructs a command with a string value

	Command_Code code() const;
	    //	Returns the command's code.

	int int_value() const;
	    //	Returns the command's integer value.

	double double_value() const;
	    //	Returns the command's double value.

	const std::string & str_value() const;
	    //	Returns the command's string value.

    private:
	Command_Code code_;
	struct Element
	{
		int	    i;
		double	    d;
		std::string s;
	} value_;
};

//-----------------------------------------------------------------------------

#include "Command.inl"

//-----------------------------------------------------------------------------

#endif
