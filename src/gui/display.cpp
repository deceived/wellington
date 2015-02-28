void StdScrMapController::Display()
{
	DisplayMap();
	DisplayKey();
	DisplayCommand();
	DisplayUnits();
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

	line_ptr prompt = command_->GetPrompt();
	view_->ClearLine( 40, 0, 80 );
	view_->Put( 40, 0, prompt );
}

void StdScrMapController::DisplayUnits()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

	logger.Severity( severity_level::info, std::string("actor count: ") + boost::lexical_cast<std::string>(actors_.size()) );

	logger.Severity( severity_level::info, std::string("actor 1: ") + actors_[0]->ToXML() );
	logger.Severity( severity_level::info, std::string("actor 2: ") + actors_[1]->ToXML() );
	logger.Severity( severity_level::info, std::string("actor 3: ") + actors_[2]->ToXML() );
	logger.Severity( severity_level::info, std::string("actor 4: ") + actors_[3]->ToXML() );
	
	for( ActorPtr actor: 	actors_ )
	{
		boost::shared_ptr<MoveComponent> move( actor->GetComponent<MoveComponent>( std::string( "MoveComponent" ) ) );

		int x = move->GetStartX();
		int y = move->GetStartY();		

		boost::shared_ptr<RepresentationComponent> representation( actor->GetComponent<RepresentationComponent>( std::string( "RepresentationComponent" ) ) );

		char c = representation->GetChar();

		view_->Put( x, y, c );

		logger.Severity( severity_level::info, std::string("start x: ") + boost::lexical_cast<std::string>( x ) );
		logger.Severity( severity_level::info, std::string("start y: ") + boost::lexical_cast<std::string>( y ) );

		
	}
}

