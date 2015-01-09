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


		int flat = map->get<int>( "terrain.flat" );
		std::cout << flat << std::endl;
		int hill = map->get<int>( "terrain.hill" );
		std::cout << hill << std::endl;
		int mountain = map->get<int>( "terrain.mountain" );
		std::cout << mountain << std::endl;
		int lake = map->get<int>( "terrain.lake" );
		std::cout << lake << std::endl;
		int stream = map->get<int>( "terrain.stream" );
		std::cout << stream << std::endl;
		int river = map->get<int>( "terrain.river" );
		std::cout << river << std::endl;

		int grass = map->get<int>( "cover.grass" );
		std::cout << grass << std::endl;
		int marsh = map->get<int>( "cover.marsh" );
		std::cout << marsh << std::endl;
		int wood = map->get<int>( "cover.wood" );
		std::cout << wood << std::endl;
		int forest = map->get<int>( "cover.forest" );
		std::cout << forest << std::endl;
		int wall = map->get<int>( "cover.wall" );
		std::cout <<  wall << std::endl;
		int building = map->get<int>( "cover.building" );
		std::cout << building << std::endl;
		int road = map->get<int>( "cover.road" );
		std::cout << road << std::endl;

		for( auto const& tiles : map->get_child( "tiles" ) )
		{
			int id = tiles.second.get<int>( "id" );
		    auto tile = boost::make_shared< Tile >( id );

			std::cout << tiles.second.get<std::string>( "terrain" ) << std::endl;

			for( auto const& cover : tiles.second.get_child( "cover." ) ) 
			{	
				std::cout << cover.second.get<std::string>("") << std::endl;
			}
		} 

		for( auto const& tiles : map->get_child( "map." ) )
		{
			for( auto const& row : tiles.second.get_child( "" ) ) 
			{	
				std::cout << row.second.get<std::string>("") << std::endl;
			}
		} 
	
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


private:

	map_ptr map_;
	key_ptr key_;
	cmd_ptr cmd_;

};

#endif

