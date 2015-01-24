#ifndef DRIVER_HPP
#define DRIVER_HPP

#include <ftream>
#include <sstream>
#include <string>

#include <boost/smart_ptr.hpp>

#include <driver.hpp>
#include <scanner.hpp>

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

	boost::scoped_ptr<Scanner> lexer_;

	boost::shared_ptr< Order > order_;
};


#endif

