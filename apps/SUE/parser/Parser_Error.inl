//-----------------------------------------------------------------------------
//  Inline function definitions:  Parser_Error struct
//-----------------------------------------------------------------------------

inline
Parser_Error::Parser_Error(const std::string & desc,
			   const std::string & token,
			   int		       position)
    : description(desc),
      current_token(token),
      token_position(position)
{
}
