#include "parser.hpp"

bool Parser::parse()
{
	while( driver_.lexer_.NextToken() )
	{
	}

	return true;
}

