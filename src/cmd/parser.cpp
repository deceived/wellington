#include "parser.hpp"

namespace order
{

bool Parser::parse()
{
	symbolclass token = driver_.lexer_->NextToken();
	while( EOFSY != token )
	{
		switch( token )
		{
			case WORD :	
				break;
			case INTEGER :
				break;
			case PERIOD :
				break;
		}
		token = driver_.lexer_->NextToken();
	}

	return true;
}

}
