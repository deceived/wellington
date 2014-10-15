#ifndef KEY_MODEL_HPP
#define KEY_MODEL_HPP

#include <string>

#include <boost/smart_ptr.hpp>

#include "key.hpp"

class KeyModel
{

public:

	typedef boost::shared_ptr< Key >	key_ptr;

	KeyModel()
	{}

	void Load( std::string fileName );

	std::string NextLine();
	size_t LineCount();

private:

	key_ptr		key_;
};

#endif

