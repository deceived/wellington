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

	bool ParseFile( const std::string& name );
	bool ParseStream( std::istream& input, const std::string& name );
	bool ParseString( const std::string& input, const std::string& name );

	void Error( const std::string& message );

private:

	std::string name_;

	boost::scoped_ptr<Scanner> lexer_;

};


#endif

