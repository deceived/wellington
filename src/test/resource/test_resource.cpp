#include <iostream>
#include <string>
#include <vector>

#include <boost/algorithm/string.hpp>

#include "resource.hpp"
#include "resource_cache.hpp"
#include "xml_doc_resource.hpp"

typedef std::vector< std::string > split_vector_type;

int main( int argc, char** argv )
{
    std::cout << "test resource..." << std::endl;

	std::string command( "load vitoria.battle.xml" );

	split_vector_type splits;
	boost::split( splits, command, boost::is_any_of( " " ) );

	XmlDocResource::xml_resource_ptr resource = boost::make_shared< XmlDocResource >( "deployment", splits[ 1 ] );

	resource->Load();

	ResourceCache cache;

	cache.Add( resource );

	ResourceCache::resource_value resource_value = cache.Get( "deployment" );
}
