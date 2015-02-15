#ifndef ORDER_HPP
#define ORDER_HPP

#include <map>
#include <vector>
#include <iostream>
#include <sstream>

#include "dictionary.hpp"

namespace order
{

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

	void Transform()
	{
		for( std::vector< std::string >::iterator it = sentence_.begin();
				it != sentence_.end();
				++it )
		{
				
		}
	}

private:

	std::vector< Entry* > entries_; 
	std::vector< std::string > sentence_;

};

#if 0
struct OrderTransform
{
	void operator()( Order* order )
	{
		order->Transform();
	}

	Dictionary	dictionary_;

} Convert;
#endif

class OrderContext
{

public:

	void Clear()
	{
		orders_.clear();
	}

	void Analyse()
	{
//		std::for_each( orders_.begin(), orders_.end(), Convert );
	}

	std::vector< Order* > orders_;

};

}
 
#endif

