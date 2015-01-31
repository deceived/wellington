#include <iostream>

#include "driver.hpp"

using namespace order;

int main( int argc, char** argv )
{

	std::cout << "starting order input test program...." << std::endl;


	OrderContext orders;

	do
	{
		std::string order;
		std::cout << "input order ";	
		getline( std::cin, order );	

		if( order == "end" )
		{
			break;
		}
		if( order.empty() )
		{
			break;
		}

		orders.Clear();
		Driver* driver = new Driver( orders );
		driver->ParseString( order, "order" );

	} while( true );
	
	return 0;
}
