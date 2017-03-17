#ifndef PROCESS_CMD_LINE_H
#define PROCESS_CMD_LINE_H

//-----------------------------------------------------------------------------

enum Cmd_Line_Status {
	Args_OK,
	Arg_Action_Done,
	Arg_Error
};

Cmd_Line_Status process_cmd_line(int	 argc,
				 char ** argv);
    //	Process command-line arguments.
    //
    //	Return value:
    //	    Args_OK		All the arguments were successfully processed.
    //
    //	    Arg_Action_Done	All the arguments were successfully processed
    //				and whatever actions they specified have been
    //				done (e.g., printing a help message).
    //
    //	    Arg_Error		An error occurred; a message explaining it
    //				was printed to standard error.

//-----------------------------------------------------------------------------

#endif
