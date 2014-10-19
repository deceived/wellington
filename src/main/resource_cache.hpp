#ifndef RESOURCE_CACHE_HPP
#define RESOURCE_CACHE_HPP

#include <map>

#include "resource.hpp"



class ResourceCache
{

public:

	typedef boost::shared_ptr< IResource > resource_value;
	typedef std::map< std::string, IResource >	resource_data;

	void Add( resource_value value )
	{
		resources_[value->Name()]  = value; 
	}

	resource_value Get( const std::string& name )
	{
		return resources_[ name ];
	}
 
private:

	resource_data	resources_;

};

#endif

