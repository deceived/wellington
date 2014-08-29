#include <iostream>
#include <string>

#include "command.hpp"



int main( int argc, char** argv )
{
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
