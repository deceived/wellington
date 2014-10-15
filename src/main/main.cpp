#include <iostream>
#include <string>

#include <boost/program_options.hpp>

#include "stdscr_map_controller.hpp"




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

int main( int argc, char** argv )
{

	StdScrMapController controller;

    return 0;
}

