#include <iostream>
#include <string>

#include <ncurses.h>

#include <boost/program_options.hpp>

#include "map.hpp"
#include "file_reader.hpp"


namespace po = boost::program_options;
po::options_description desc("Allowed options");
po::variables_map vm;

bool program_options( int argc, char** argv )
{
	try
	{
        po::options_description desc("Allowed options");
		desc.add_options()
    		("help", "help message")
    		("map", po::value<std::string>()->default_value( "vitoria.txt" ), "load current map")
    		;

        po::store( po::parse_command_line( argc, argv, desc ), vm );
        po::notify( vm );    

        if( vm.count("help") ) 
        {
            std::cout << desc << "\n";
            return false;
        }

        if( vm.count("map") ) 
        {
            std::cout << "map details read from '" 
                      << vm["map"].as<std::string>() << "'.\n";
        } 
        else 
        {
            std::cout << "no map specified.\n";
        }
    }
    catch( const std::exception& e )
    {
        std::cout << "error : " << e.what() << std::endl;
        return false; 
    }
	return true;
}

void load_map()
{
	boost::shared_ptr< Map > map = boost::make_shared< Map >();
	map->Load( vm["map"].as<std::string>() );
	unsigned int rows = map->GetRows();
	
	for( unsigned int i = 0; 
		i < rows;
		++i
		)
	{
		boost::shared_ptr< std::string > line = map->GetRow( i );
	    mvprintw( i, 0, "%s", (*line).c_str() );	
	}
}

void load_key()
{
	FileReader::data keys = FileReader::Load( "map_key.txt" );
	unsigned int count = 0;
	for( FileReader::data_type::iterator it = keys->begin();
		it != keys->end();
		++it
		)
	{
		mvprintw( count++, 100, "%s", (*it)->c_str() );
	}
}

int main( int argc, char** argv )
{
	int row, col;

	char  prompt[] = "Enter command: ";
	char  cmd[80];

	if( !program_options( argc, argv ) )
	{
		exit(1);
	}

    initscr();
	raw();
	keypad(stdscr, TRUE);
	getmaxyx( stdscr, row, col );
    refresh();

	load_map();
	load_key();

	mvprintw( row-1, 0, "%s", prompt );
	getstr( cmd );
//	mvprintw( 0, 0, "Command: %s", cmd );
	getch();
  
    endwin();

    return 0;
}

