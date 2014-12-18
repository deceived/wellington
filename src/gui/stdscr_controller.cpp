#include "stdscr_controller.hpp"



void StdScrMapController::Init()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
 
	view_->Init();

	Reset();
}

void StdScrMapController::Terminate()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	view_->Terminate();
}

void StdScrMapController::Reset()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	LoadMap();
	LoadKey();

	DisplayMap();
	DisplayKey();
	DisplayCommand();
}

void StdScrMapController::LoadMap()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	model_->LoadMap( options_["map"].as<std::string>() );
}

void StdScrMapController::LoadKey()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	model_->LoadKey( options_["key"].as<std::string>() );
}

void StdScrMapController::DisplayMap()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	StdScrModel::map_ptr model = model_->GetMap();

	size_t rows = model->LineCount();
	for( size_t count = 0;
			count < rows;
			++count
		)
	{
		line_ptr line = model->NextLine( count );
		view_->Put( count, 0, line );
	}
}

void StdScrMapController::DisplayKey()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	StdScrModel::key_ptr model = model_->GetKeyModel();

	size_t rows = model->LineCount();
	for( size_t count = 0;
			count < rows;
			++count
		)
	{
		line_ptr line = model->NextLine( count );
		view_->Put( count, 100, line );
	}
}

void StdScrMapController::DisplayCommand()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	StdScrModel::cmd_ptr model = model_->GetCmdModel();

	line_ptr prompt = model->GetPrompt();

	view_->Put( 40, 0, prompt );
}

void StdScrMapController::ClearCmd()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	view_->ClearLine( 40, 0, 80 );

	DisplayCommand();
}

StdScrMapController::line_ptr StdScrMapController::ReadCmd()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	StdScrModel::cmd_view view = view_->GetCmdView();
	return view->Read();
}

void StdScrMapController::UpdateMap()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
}

void StdScrMapController::Load( line_ptr command )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	split_vector_type splits;
	boost::split( splits, *command, boost::is_any_of( " " ) );

	XmlDocResource::xml_resource_ptr resource = boost::make_shared< XmlDocResource >( "deployment", splits[ 1 ] );

	resource->Load();

	cache_.Add( resource );
}

void StdScrMapController::InitialiseDisplay()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	XmlDocResource::xml_resource_ptr res = boost::static_pointer_cast< XmlDocResource >( cache_.Get( "deployment" ) );

	Properties::pointer xml = res->Get();

	pugi::xml_node map = (*xml).child( "Battle" ).child( "Map" );
	for( pugi::xml_node child: map.children() )
	{
		logger.Severity( severity_level::info, std::string( "battle.map.child: " ) + child.name() );
	}

	pugi::xml_node units = (*xml).child( "Battle" ).child( "Units" );
	for( pugi::xml_node unit: units.children( "Unit" ) )
	{
		logger.Severity( severity_level::info, std::string( "battle.units.unit: " ) + unit.name() );
		for( pugi::xml_node element: unit.children() )
		{
			logger.Severity( severity_level::info, std::string( "unit.child.name: "  ) + element.name() );
			logger.Severity( severity_level::info, std::string( "unit.child.value: "  ) + element.child_value() );
			if( element.name() == std::string( "Actor" ) )
			{
				ActorPtr actor = actorFactory_.CreateActor( element.child_value() );
			}
			if( element.name() == std::string( "StartX" ) )
			{
			}
			if( element.name() == std::string( "StartY" ) )
			{
			}
		}
	} 
}

void StdScrMapController::LoadActor( const std::string actorName )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
}

void StdScrMapController::Run()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
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

