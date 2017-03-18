//-----------------------------------------------------------------------------
//  Inline function definitions:  Output_Column class
//-----------------------------------------------------------------------------

inline
int Output_Column::spacing() const
{
    return spacing_;
}

//-----------------------------------------------------------------------------

inline
const std::string & Output_Column::spacing_str() const
{
    return spacing_str_;
}

//-----------------------------------------------------------------------------

inline
const Multi_Line_Text & Output_Column::title() const
{
    return title_;
}

//-----------------------------------------------------------------------------

inline
int Output_Column::width() const
{
    return width_;
}
