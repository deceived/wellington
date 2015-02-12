#ifndef ORDER_HPP
#define ORDER_HPP

#include <map>
#include <vector>
#include <iostream>
#include <sstream>

class Order 
{

public:

	void Add( const std::string& value )
	{
		sentence_.push_back( value );
	}

private:

	std::vector< Entry* > entries_; 
	std::vector< std::string > sentence_;

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

