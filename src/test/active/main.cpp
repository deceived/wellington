#include <iostream>

#include "add_proxy.hpp"

int main( int argc, char** argv )
{

	const std::size_t max_threads = 1;
	const std::size_t max_requests = 3;

	priority_scheduler scheduler( max_threads, max_requests );

	AddProxy adder( scheduler );

	return 0;
}
