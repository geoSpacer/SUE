#include "pragmas.h"

#include <string>

#include "Input_Value_error_message.h"
#include "Input_Value.h"
#include "Input_Value_Error.h"

//-----------------------------------------------------------------------------

Multi_Line_Text Input_Value::error_message(const Input_Value::Error & error,
					   const std::string &	      where)
{
    Multi_Line_Text mesg("Error " + where + ":");
    Multi_Line_Text error_mesg = error.message();
    for (int i = 0; i < error_mesg.line_count(); i++)
	mesg += "  " + error_mesg[i];
    return mesg;
}

//-----------------------------------------------------------------------------

Multi_Line_Text Message::error_with_value(const Input_Value::Error & error)
{
    if (error.name() == "")
	return error.message();
    else
	return Input_Value::error_message(error, "with the input value \""
						 + error.name() + "\"");
}

//-----------------------------------------------------------------------------

Multi_Line_Text Message::error_in_column(const Input_Value::Error & error)
{
    return Input_Value::error_message(error,"in the \"" + error.name()
							+ "\" column");
}
