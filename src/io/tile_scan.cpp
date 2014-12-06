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
    if( !input.eof() )
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
				break;
		    case DIGIT:
				break;
			case '{':
				break;
			case '}':
				break;
			case '[':
				break;
			case ']':
				break;
			case '(':
				break;
			case ')':
				break;
			case '=':
				break;
		}
	}
}
