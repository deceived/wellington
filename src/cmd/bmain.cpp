#include <iostream>

#include "driver.hpp"

using namespace order;

int main( int argc, char** argv )
{

	std::cout << "starting...." << std::endl;

	Order order;

	Driver* driver = new Driver( order );
	
	return 0;
}
