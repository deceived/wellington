#include <iostream>

#include "driver.hpp"

using namespace order;

int main( int argc, char** argv )
{

	std::cout << "starting order input test program...." << std::endl;

	OrderContext orders;
	Driver driver( orders );

	if( argc > 1 )
	{
		for( int i = argc; i < argc; ++i )
		{
			if( argv[i] == std::string( "-p" ) )
			{
				driver.trace_parsing = true;
			}
			else if( argv[i] == std::string( "-s" ) )
			{
				driver.trace_scanning = true;
			}
			else
			{
				std::fstream infile( argv[i] );
				if( !infile.good() )
				{
					std::cout << "cannot open input file : [" << argv[i] << "]" << std::endl;
					return 0;
				}
				orders.Clear();
				bool result = driver.ParseStream( infile, argv[ai] );
				if ( result )
				{
					std::cout << "orders: " << std::endl;
					for( int o = 0; o < orders_.orders_.size(); ++o )
					{
						orders_.orders_[o]->Print( std::cout );
					}
				}	
			}
			return 0;
		}	
	}

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
		driver.ParseString( order, "order" );

	} while( true );
	
	return 0;
}
