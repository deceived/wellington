#ifndef KEY_MODEL_HPP
#define KEY_MODEL_HPP

#include <string>

#include <boost/smart_ptr.hpp>

#include "key.hpp"

class KeyModel
{

public:

	typedef boost::shared_ptr< Key >	key_ptr;
	typedef boost::shared_ptr< std::string > line_ptr;

	KeyModel()
		: key_( boost::make_shared< Key >() )
	{}

	void Load( std::string fileName );

	line_ptr NextLine( size_t line );
	size_t LineCount();

private:

	key_ptr		key_;
};

#endif

