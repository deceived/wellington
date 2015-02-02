#include <iostream>

#include "driver.hpp"

using namespace order;

int main( int argc, char** argv )
{

	std::cout << "starting order input test program...." << std::endl;

	OrderContext orders;
	Driver driver( orders );

	for( int i = 1; i < argc; ++i )
	{
		std::cout << "argument loop\n";
		if( argv[i] == std::string( "-p" ) )
		{
			std::cout << "trace parsing = true" << std::endl;
			driver.traceParsing_ = true;
		}
		else if( argv[i] == std::string( "-s" ) )
		{
			std::cout << "trace scanning = true" << std::endl;
			driver.traceScanning_ = true;
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
			bool result = driver.ParseStream( infile, argv[i] );
			if ( result )
			{
				std::cout << "orders: " << std::endl;
				for( unsigned int o = 0; o < driver.orders_.orders_.size(); ++o )
				{
					driver.orders_.orders_[o]->Print( std::cout );
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
		bool result = driver.ParseString( order, "order" );
		if ( result )
		{
			std::cout << "orders: " << std::endl;
			for( unsigned int o = 0; o < driver.orders_.orders_.size(); ++o )
			{
				driver.orders_.orders_[o]->Print( std::cout );
			}
		}	

	} while( true );
	
	return 0;
}
