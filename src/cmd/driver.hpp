#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <fstream>
#include <sstream>
#include <string>

#include <boost/smart_ptr.hpp>

#include "order.hpp"
#include "scanner.hpp"

namespace order
{

class Driver
{

public:

	Driver( class OrderContext& order );

	bool ParseFile( const std::string& name );
	bool ParseStream( std::istream& input, const std::string& name );
	bool ParseString( const std::string& input, const std::string& name );

	void Error( const class location& l, const std::string& m );
	void Error( const std::string& message );

	std::string name_;

	class Scanner* lexer_;

	class OrderContext& orders_;

	bool traceParsing_;
	bool traceScanning_;

};

}

#endif

