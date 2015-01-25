#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <fstream>
#include <sstream>
#include <string>

#include <boost/smart_ptr.hpp>

class Driver
{

public:

	Driver( boost::shared_ptr< Order > order );

	bool ParseFile( const std::string& name );
	bool ParseStream( std::istream& input, const std::string& name );
	bool ParseString( const std::string& input, const std::string& name );

	void Error( const std::string& message );

private:

	std::string name_;

	Scanner& lexer_;

	boost::shared_ptr< Order > order_;
};


#endif

