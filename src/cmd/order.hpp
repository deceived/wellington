#ifndef ORDER_HPP
#define ORDER_HPP

#include <map>

class Context
{

public:

	void Add( const std::string& key, const std::string& value );
	std::string Get( const std::string& key );

private:

	std::map< std::string, std::string > meanings_;

};

#endif

