#ifndef STDSCR_MODEL_HPP
#define STDSCR_MODEL_HPP

#include <boost/smart_ptr.hpp>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>

#include "logger.hpp"

#include "map.hpp"
#include "key.hpp"
#include "cmd.hpp"

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
		Properties::ptr map = map_->Load( fileName );
		//write_json( std::cout, *map );

		std::cout << map->get<std::string>( "terrain.flat" ) << std::endl;
		std::cout << map->get<std::string>( "terrain.hill" ) << std::endl;
		std::cout << map->get<std::string>( "terrain.mountain" ) << std::endl;
		std::cout << map->get<std::string>( "terrain.lake" ) << std::endl;
		std::cout << map->get<std::string>( "terrain.stream" ) << std::endl;
		std::cout << map->get<std::string>( "terrain.river" ) << std::endl;

		std::cout << map->get<std::string>( "cover.grass" ) << std::endl;
		std::cout << map->get<std::string>( "cover.marsh" ) << std::endl;
		std::cout << map->get<std::string>( "cover.wood" ) << std::endl;
		std::cout << map->get<std::string>( "cover.forest" ) << std::endl;
		std::cout << map->get<std::string>( "cover.wall" ) << std::endl;
		std::cout << map->get<std::string>( "cover.building" ) << std::endl;
		std::cout << map->get<std::string>( "cover.road" ) << std::endl;

		BOOST_FOREACH( boost::property_tree::ptree::value_type& tiles, map->get_child( "tiles" ) )
		{
			std::cout << tiles.second.get<std::string>( "id" ) << std::endl;
			std::cout << tiles.second.get<std::string>( "terrain" ) << std::endl;
			BOOST_FOREACH( boost::property_tree::ptree::value_type& cover, tiles.second.get_child( "cover." ) )
			{	
				std::cout << cover.second.get<std::string>("") << std::endl;
			}
		} 
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

