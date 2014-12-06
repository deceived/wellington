#include "tile_scan.hpp"

int TileScanner::Class( int c )
{
    if( isalpha( c ) )
    {
		return ALPHA;
    }
    if( isdigit( c ) )
    {
    	return DIGIT;
    }
    return c;
}

int TileScanner::Input()
{
	if( index_ < line_.size() )
	{
		return line_[ index_++ ];
	}
    if( !input_.eof() )
    {
		getline( input_, line_ );
		boost::to_lower( line_ );
		index_ = 0;
		return line_[ index_++ ];
    }
}

void TileScanner::Unput()
{
	--input_;
}

int TileScanner::NextSymbol()
{
	int c;
	c = Input();
	while( c != EOFSY )
	{
		switch( Class( c ) )
		{
			case ' ':
			case '\t':
			case '\n':
				break;
			case ALPHA:
				for( j = 0; isalnum( c ); j++ )
				{
					token_ += c;
					c = Input();
				}
				Unput();
				return reserved_.Get( token_ );
				break;
		    case DIGIT:
				for( i = 0; isdigit( c ); j++ )
				{
					token_ += c;
					c = Input();
				}
				Unput();
				return INTCONST;
				break;
			case '{':
				return LEFTBRACKETSY;
				break;
			case '}':
				return RIGHTBRACKETSY;
				break;
			case '[':
				return LEFTSQUARESY;
				break;
			case ']':
				return RIGHTSQUARESY;
				break;
			case '(':
				return LEFTPARENTSY;
				break;
			case ')':
				return RIGHTPARENTSY;
				break;
			case '=':
				return EQUALSY;
				break;
			case ',':
				return COMMASY;
				break;
		}
	}
}
