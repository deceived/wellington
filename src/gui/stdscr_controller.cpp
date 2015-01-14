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

	StdScrModel::map_ptr map = model_->GetMap();
	std::vector< Tile > tiles = model_->GetTiles();

	logger.Severity( severity_level::info, map->ToString() );
	for( int i = 0; i < tiles.size(); ++i )
	{
		logger.Severity( severity_level::info, tiles[i].ToString() );
	}

	for( size_t row = 0;
		 row < map->rows_;
		 ++row
		)
	{
		for( size_t col = 0;
			 col < map->cols_;
			 ++col )
		{
			view_->Put( row, col, tiles[ map->map_tiles[ row ][ col ] - 1 ].terrain_representation_ );
		}
	}
}

void StdScrMapController::DisplayKey()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	StdScrModel::key_ptr key = model_->GetKey();

	size_t rows = key->LineCount();
	for( size_t count = 0;
			count < rows;
			++count
		)
	{
		line_ptr line = key->NextLine( count );
		view_->Put( count, 100, line );
	}
}

void StdScrMapController::DisplayCommand()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	StdScrModel::cmd_ptr command = model_->GetCmd();

	line_ptr prompt = command->GetPrompt();

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
	StdScrModel::cmd_ptr command = model_->GetCmd();
	return command->Read();
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

