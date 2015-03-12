#include "scheduler.hpp"

Scheduler::Scheduler( std::size_t maxThreads, std::size_t maxRequests )
	:	work_( ioService_ ),
		maxRequests_( maxRequests ),
		requestCount_( 0 )
{
	for( std::size_t i = 0; i < maxThreads; ++i )
	{
		threads_.create_thread( boost::bind( &boost::asio::io_service::run, &ioService_ ) );
	}
}

Scheduler::~Scheduler()
{
	ioService_.stop();
	threads_.join_all();
}

void Scheduler::Insert( Request::request_ptr request )
{}

void Scheduler::Dispatch()
{}
