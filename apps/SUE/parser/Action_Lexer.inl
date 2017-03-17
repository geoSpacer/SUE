//-----------------------------------------------------------------------------
//  Inline function definitions:  Action_Lexer class
//-----------------------------------------------------------------------------

inline
std::string Action_Lexer::token() const
{
    return token_;
}

//-----------------------------------------------------------------------------

inline
int Action_Lexer::token_type() const
{
    return token_type_;
}

//-----------------------------------------------------------------------------

inline
int Action_Lexer::token_position() const
{
    return token_start_;
}
