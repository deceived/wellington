#include "map_controller.hpp"


void MapController::LoadMap()
{
	map_->Load( vm["map"].as<std::string>() );
}

void MapController::LoadKey()
{
	FileReader::data keys = FileReader::Load( "map_key.txt" );
}

void MapController::DisplayMap()
{
	unsigned int rows = map_->GetRows();
	
	for( unsigned int i = 0; 
		i < rows;
		++i
		)
	{
		boost::shared_ptr< std::string > line = map->GetRow( i );
	    mvprintw( i, 0, "%s", (*line).c_str() );	
	}
}

void MapController::DisplayKey()
{
}

void MapController::DisplayCommand()
{
}

