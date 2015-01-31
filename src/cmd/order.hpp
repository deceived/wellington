#ifndef ORDER_HPP
#define ORDER_HPP

#include <map>
#include <vector>
#include <iostream>
#include <sstream>

class Order 
{

public:

	virtual ~Order()
	{}

	void Add( const std::string& key, const std::string& value );
	std::string Get( const std::string& key )
	{
		return details_[ key ];
	}

	virtual void Print( std::ostream& os ) = 0;
	virtual std::string ToString() = 0;

protected:

	std::map< std::string, std::string > details_;

};

class MoveOrder : public Order
{

public:

	MoveOrder( const std::string& direction )
	{
		details_[ "direction" ] = direction;
	}

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

class OrderContext
{

public:

	void Clear()
	{
		orders_.clear();
	}

	std::vector< Order* > orders_;

};
 
#endif

