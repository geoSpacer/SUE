//-----------------------------------------------------------------------------
//  Inline function definitions:  Input_Value::Error class
//				  Input_Value_Error::Custom class
//-----------------------------------------------------------------------------

inline
const std::string & Input_Value::Error::name() const
{
    return name_;
}

//-----------------------------------------------------------------------------

inline
Multi_Line_Text Input_Value_Error::Custom::message() const
{
    return message_;
}
