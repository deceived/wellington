#include "driver.hpp"

namespace order
{

Driver::Driver( class OrderContext& orders )
	: 	orders_( orders ),
		traceParsing_( false ),
		traceScanning_( false )
{}

bool Driver::ParseStream( std::istream& input, const std::string& name )
{
	Scanner scanner( &input );
	lexer_ = &scanner;

	Parser parser( *this );

	parser.set_debug_level( traceParsing_ );
	
	return parser.parse() == 0;
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

void Driver::Error( const class location& l, const std::string& message )
{
}

void Driver::Error( const std::string& message )
{
}

}
