//-----------------------------------------------------------------------------
//  Inline function definitions:  Input_Value_Error::Bad_Value class
//				  Input_Value_Error::Not_In_Range class
//-----------------------------------------------------------------------------

//-----------------------------------------------------------------------------
//  Input_Value_Error::Bad_Value class
//-----------------------------------------------------------------------------

inline
const std::string & Input_Value_Error::Bad_Value::description() const
{
    return description_;
}

//-----------------------------------------------------------------------------

inline
const std::string & Input_Value_Error::Bad_Value::value() const
{
    return value_;
}

//-----------------------------------------------------------------------------
//  Input_Value_Error::Not_In_Range class
//-----------------------------------------------------------------------------

inline
const std::string & Input_Value_Error::Not_In_Range::range() const
{
    return range_;
}
