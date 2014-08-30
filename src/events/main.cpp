#include <iostream>
#include <string>

#include <boost/program_options.hpp>

#include "command.hpp"

namespace po = boost::program_options;



int main( int argc, char** argv )
{
    try
    {
        po::options_description desc("Allowed options");
        desc.add_options()
            ("help", "help message")
            ("units", po::value<std::string>(), "unit definitions")
            ("map", po::value<std::string>(), "load current map")
            ("rules", po::value<std::string>(), "load rule set")
            ("moves", po::value<std::string>(), "load moves")
            ;
 
        po::variables_map vm;
        po::store( po::parse_command_line( argc, argv, desc ), vm );
        po::notify( vm );    

        if( vm.count("help") ) 
        {
            std::cout << desc << "\n";
            return 1;
        }

        if( vm.count("units") ) 
        {
            std::cout << "unit details read from " 
                      << vm["units"].as<std::string>() << ".\n";
        } 
        else 
        {
            std::cout << "no unit details specified.\n";
        }

        if( vm.count("map") ) 
        {
            std::cout << "map details read from " 
                      << vm["map"].as<std::string>() << ".\n";
        } 
        else 
        {
            std::cout << "no map specified.\n";
        }

        if( vm.count("rules") ) 
        {
            std::cout << "rule details read from " 
                      << vm["rules"].as<std::string>() << ".\n";
        } 
        else 
        {
            std::cout << "no rules specified.\n";
        }
    }
    catch( const std::exception& e )
    {
        std::cout << "error : " << e.what() << std::endl;
        return 1; 
    }



    std::string line;

    do
    {
        std::cout << ". ";
        std::getline( std::cin, line );

        boost::shared_ptr<ICommand> command = ParseCommand( line );

        if( command != 0 )
        {
            std::cout << command->ToString() << std::endl;
            command->Execute();
        }

    } while( line != "done" );    

    return 0;
}
