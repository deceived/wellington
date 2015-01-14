#ifndef STDSCR_MODEL_HPP
#define STDSCR_MODEL_HPP

#include <boost/smart_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>

#include "logger.hpp"

#include "map.hpp"
#include "key.hpp"
#include "cmd.hpp"
#include "tile.hpp"

extern Log logger;

class StdScrModel
{

public:

	typedef boost::shared_ptr< StdScrModel > model_ptr;

	typedef boost::shared_ptr< std::string > line_ptr;

	typedef boost::shared_ptr< Map > map_ptr;
	typedef boost::shared_ptr< Key > key_ptr;
	typedef boost::shared_ptr< Command > cmd_ptr;

	StdScrModel()
		: map_( boost::make_shared< Map >() ),
		  key_( boost::make_shared< Key >() ),
          cmd_( boost::make_shared< Command >() )
	{}

	void LoadMap( const std::string& fileName )
	{
		logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
		Properties::ptr map = Load( fileName );
		//write_json( std::cout, *map );

		for( auto const& tiles : map->get_child( "tiles" ) )
		{
			Tile tile;

			int id = tiles.second.get<int>( "id" );
			tile.id_ = id;

			tile.terrain_ = tiles.second.get<int>( "terrain" );
			tile.terrain_representation_ = tiles.second.get<char>( "terrain" );

			for( auto const& cover : tiles.second.get_child( "cover." ) ) 
			{	
				int c = cover.second.get<int>( "" );
				tile.cover_.push_back( c );
			}
	
			tiles_.push_back( tile ); 
			logger.Severity( severity_level::info, tile.ToString() );
		} 

		int row_count = 0;
		int col_count = 0;

		for( auto const& row : map->get_child( "map." ) )
		{
			++row_count;

			for( auto const& col : row.second.get_child( "" ) ) 
			{	
				++col_count;

				map_->map_tiles[ row_count ][ col_count ] = col.second.get<int>( "" );
			}
		} 

		map_->rows_ = row_count;
		map_->cols_ = col_count;
	
	}

	Properties::ptr Load( const std::string& fileName )
	{
		return Properties::ReadJson( fileName ); 
	}

	void LoadKey( const std::string& fileName )
	{
		logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
		key_->Load( fileName );
	}

	void LoadCmd( const std::string& fileName )
	{
		logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
		cmd_->Load( fileName );
	}

	line_ptr GetPrompt();
	line_ptr NextLine( size_t line );

	map_ptr	GetMap()
	{
		return map_;
	}

	cmd_ptr GetCmd()
	{
		return cmd_;
	}

	key_ptr GetKey()
	{
		return key_;
	}

	std::vector<Tile> GetTiles()
	{
		return tiles_;
	}


private:

	map_ptr map_;
	key_ptr key_;
	cmd_ptr cmd_;

	std::vector< Tile > tiles_;

};

#endif

