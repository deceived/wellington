#include <iostream>

#include "add_proxy.hpp"

bool get( bool& value )
{
	return value;
}

void guarded_call()
{
	std::cout << "guarded call" << std::endl;
}

int main( int argc, char** argv )
{

	const std::size_t max_threads = 1;
	const std::size_t max_requests = 3;

	priority_scheduler scheduler( max_threads, max_requests );

	AddProxy adder( scheduler );

#if 0
	bool ready = false;
	std::cout << "add guarded method" << std::endl;
	boost::unique_future<void> future1 = scheduler.Insert(
		boost::bind( &get, boost::ref( ready )),
		&guarded_call );
#endif

	return 0;
}
