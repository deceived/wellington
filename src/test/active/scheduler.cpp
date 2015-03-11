#include "scheduler.hpp"

Scheduler::Scheduler( std::size_t maxThreads, std::size_t maxRequests )
	:	work_( ioService_ ),
		maxRequests_( maxRequests ),
		requestCount_( 0 )
{}

void Scheduler::Insert( Request::request_ptr request )
{}

void Scheduler::Dispatch()
{}
