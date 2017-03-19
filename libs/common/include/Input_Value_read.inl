//-----------------------------------------------------------------------------
//  Inline function definitions:  Input_Value_Error::Name class
//				  Input_Value_Error::Extra_Text class
//
//  These classes are used to represent errors by the "read" function for
//  input values.
//-----------------------------------------------------------------------------

namespace Input_Value_Error
{
    //-------------------------------------------------------------------------
    //	Name class
    //-------------------------------------------------------------------------

    inline
    const std::list<std::string> & Name::expected_names() const
    {
	return expected_names_;
    }

    //-------------------------------------------------------------------------

    inline
    const std::string & Name::name_found() const
    {
	return name_found_;
    }

    //-------------------------------------------------------------------------
    //	Extra_Text class
    //-------------------------------------------------------------------------

    inline
    const std::string & Extra_Text::text() const
    {
	return text_;
    }

    //-------------------------------------------------------------------------
};
