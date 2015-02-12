#ifndef ORDER_HPP
#define ORDER_HPP

#include <map>
#include <vector>
#include <iostream>
#include <sstream>

#include "dictionary.hpp"

class Order 
{

public:

	void Add( const std::string& value )
	{
		sentence_.push_back( value );
	}

	void Add( Entry* entry )
	{
		entries_.push_back( entry );
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

