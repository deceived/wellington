#include "stdscr_map_controller.hpp"



void StdScrMapController::Init()
{
	std::cout << "init()" << std::endl;
}

void StdScrMapController::LoadMap()
{
//	map_->Load( vm["map"].as<std::string>() );
}

void StdScrMapController::LoadKey()
{
}

void StdScrMapController::DisplayMap()
{
#if 0
	unsigned int rows = map_->GetRows();
	
	for( unsigned int i = 0; 
		i < rows;
		++i
		)
	{
		boost::shared_ptr< std::string > line = map->GetRow( i );
	    mvprintw( i, 0, "%s", (*line).c_str() );	
	}
#endif
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
	return "";
}

void StdScrMapController::UpdateMap()
{
}

