#include "stdscr_map_controller.hpp"



void StdScrMapController::Init()
{
	view_->Init();

	Reset();
}

void StdScrMapController::Terminate()
{
	view_->Terminate();
}

void StdScrMapController::Reset()
{
	LoadMap();
	LoadKey();

	DisplayMap();
	DisplayKey();
	DisplayCommand();
}

void StdScrMapController::LoadMap()
{
	model_->LoadMap( options_["map"].as<std::string>() );
}

void StdScrMapController::LoadKey()
{
	model_->LoadKey( options_["key"].as<std::string>() );
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
		view->Put( count, 0, line );
	}
}

void StdScrMapController::DisplayKey()
{
	StdScrModel::key_model model = model_->GetKeyModel();
	StdScrView::key_view view = view_->GetKeyView();

	size_t rows = model->LineCount();
	for( size_t count = 0;
			count < rows;
			++count
		)
	{
		KeyModel::line_ptr line = model->NextLine( count );
		view->Put( count, 100, line );
	}
}

void StdScrMapController::DisplayCommand()
{
	StdScrModel::cmd_model model = model_->GetCmdModel();
	StdScrView::cmd_view view = view_->GetCmdView();

	CmdView::line_ptr prompt = model->GetPrompt();

	view->Put( 40, 0, prompt );
}

void StdScrMapController::ClearCmd()
{
	StdScrView::cmd_view view = view_->GetCmdView();
	view->ClearLine( 40, 0, 80 );

	DisplayCommand();
}

StdScrMapController::line_ptr StdScrMapController::ReadCmd()
{
	StdScrView::cmd_view view = view_->GetCmdView();
	return view->Read();
}

void StdScrMapController::UpdateMap()
{
}

void StdScrMapController::Load( line_ptr command )
{
	split_vector_type splits;
	boost::split( splits, *command, boost::is_any_of( " " ) );

	XmlFileResource::xml_resource_ptr resource = boost::make_shared< XmlFileResource >( "initial_deployment", splits[ 1 ] );

	resource->Load();

	cache_.Add( resource );
}

void StdScrMapController::InitialiseDisplay()
{
}

void StdScrMapController::Run()
{
	do
	{
		line_ptr command = ReadCmd();
		if( *command == "end" )
		{
			break;
		}
		if( *command == "reset" )
		{
			Reset();
		}
		if( command->find( "load" ) == 0 )
		{
			Load( command );
			InitialiseDisplay();
		}

		ClearCmd();
	}
	while ( true );
}
