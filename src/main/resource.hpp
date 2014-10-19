#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <string>

#include <boost/smart_ptr.hpp>


class IResource
{

public:

	typedef boost::shared_ptr< IResource >	resource_ptr;

	void Load() = 0;
	std::string Name() = 0;

};

class Resource : public IResource
{

public:

	Resource( std::string& name )
		: name_( name )
	{}

	void Load()
	{}

	std::string Name()
	{
		return name_;
	}

private:

	std::string name_;

};

#endif

