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
	StdScrView::map_view view = view_->GetMapView();

	size_t rows = model->LineCount();
	for( size_t count = 0;
			count < rows;
			++count
		)
	{
		MapModel::line_ptr line = model->NextLine( count );
		std::cout << (*line) << std::endl;
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
	return "";
}

void StdScrMapController::UpdateMap()
{
}

