#include "map_controller.hpp"


void MapController::LoadMap()
{
	map_->Load( vm["map"].as<std::string>() );
}

void MapController::LoadKey()
{
	FileReader::data keys = FileReader::Load( "map_key.txt" );
}

