#include "stdscr_map_controller.hpp"



void StdScrMapController::Init()
{
	LoadMap();
	LoadKey();

	DisplayMap();
	DisplayKey();
}

void StdScrMapController::LoadMap()
{
	model_->Load( options_["map"].as<std::string>() );
}

void StdScrMapController::LoadKey()
{
}

void StdScrMapController::DisplayMap()
{
	StdScrModel::map_model model = model_->GetMapModel();
	size_t rows = model->LineCount();
	for( size_t count = 0;
			count < rows;
			++count
		)
	{
		MapModel::line_ptr line = model->NextLine();
		std::cout << (*line) << std::endl;
	}

#if 0
	
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

