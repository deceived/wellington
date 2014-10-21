#include "battle.hpp"


void Battle::Load( const std::string& filename )
{
	XmlFileResource::xml_resource_ptr resource = boost::make_shared< XmlFileResource >( "initial_deployment", filename );

	resource->Load();
}


