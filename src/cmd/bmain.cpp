#include <iostream>

#include "driver.hpp"

using namespace order;

int main( int argc, char** argv )
{

	std::cout << "starting...." << std::endl;

	std::string move_1( "MOVE TO THE NW." );

	Order order;

	Driver* driver = new Driver( order );

	driver->ParseString( move_1, "move" );
	
	return 0;
}
