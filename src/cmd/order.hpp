#ifndef ORDER_HPP
#define ORDER_HPP

#include <map>
#include <iostream>
#include <sstream>

class Order 
{

public:

	virtual ~Order()
	{}

	void Add( const std::string& key, const std::string& value );
	std::string Get( const std::string& key );

	virtual void Print( std::ostream& os ) = 0;
	virtual std::string ToString() = 0;

private:

	std::map< std::string, std::string > meanings_;

};

class MoveOrder : public Order
{

public:

	virtual void Print( std::ostream& os )
	{
		os << ToString() << std::endl;
	}

	virtual std::string ToString()
	{
		std::stringstream os;
		os << "MOVE " << "TO " << "THE " << Get( "direction" ) << "." << std::endl;
		return os.str();
	}

};

#endif

