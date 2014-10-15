#include "map_controller.hpp"


void StdScrMapController::LoadMap()
{
	map_->Load( vm["map"].as<std::string>() );
}

void StdScrMapController::LoadKey()
{
}

void StdScrMapController::DisplayMap()
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

void StdScrMapController::DisplayKey()
{
}

void StdScrMapController::DisplayCommand()
{
}

void StdScrMapController::ClearCmd()
{
}

std::string StdScrMapController::ReadCmd()
{
}

void StdScrMapController::UpdateMap()
{
}

