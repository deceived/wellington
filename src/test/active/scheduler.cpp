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

template< 	typename ReadyFunctor,
			typename RunFunctor >
	boost::unique_future< typename boost::result_of< RunFunctor() >::type >
Scheduler::Insert( 	const ReadyFunctor& ready_function,
					const RunFunctor& run_function )
{
	typedef typename boost::result_of<RunFunctor()>::type result_type;
	typedef boost::unique_future<result_type> future_type;

	boost::unique_lock<mutex_type> lock( mutex_ );

	if( maxRequests_ && requestCount_ == maxRequests_ )
	{
		return future_type();
	}

	++requestCount_;

	typedef boost::packaged_task<result_type> task_type;

	boost::shared_ptr< task_type > task = boost::make_shared< task_type >( run_function );

}

void Scheduler::Insert( Request::request_ptr request )
{}

void Scheduler::Cancel()
{
	boost::unique_lock<mutex_type> lock( mutex_ );
	//activationList_.clear();
	requestCount_ = 0;
}

void Scheduler::Dispatch()
{}
