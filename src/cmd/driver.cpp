#include "driver.hpp"

Driver::Driver( class Order& order )
	: order_( order )
{}

bool Driver::ParseStream( std::istream& input, const std::string& name )
{
	Scanner scanner( input );
	lexer_ = &scanner;

	Parser parser( *this );
	
	return parser.Parse() == 0;
}

bool Driver::ParseString( const std::string& input, const std::string& name )
{
	std::istringstream in( input );
	return ParseStream( in, name );
}

bool Driver::ParseFile( const std::string& name )
{
	std::ifstream input( name.c_str() );
	return ParseStream( input, name );
}

void Driver::Error( const std::string& message )
{
}
