#ifndef ORDER_HPP
#define ORDER_HPP

#include <map>
#include <vector>
#include <iostream>
#include <sstream>

#include "order_dictionary.hpp"

namespace order
{

class Order 
{

public:

	typedef boost::shared_ptr< Order > order_ptr;

	void Add( const std::string& value )
	{
		sentence_.push_back( value );
	}

	void Add( Dictionary::entry_ptr entry )
	{
		entries_.push_back( entry );
	}

private:

	std::vector< Dictionary::entry_ptr > entries_; 
	std::vector< std::string > sentence_;

};

class OrderContext
{

public:

	OrderContext( const Dictionary& dictionary )
		: dictionary_( dictionary )
	{}

	void Clear()
	{
		orders_.clear();
	}

	void Analyse()
	{
		for( 	std::vector< Order::order_ptr >::iterator it = orders_.begin();
				it != orders_.end();
				++it )
		{
			
		}
	}

	std::vector< Order::order_ptr > orders_;

	const Dictionary&	dictionary_;

};

}
 
#endif

