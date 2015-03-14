#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <cstddef>

#include <boost/smart_ptr.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>
#include <boost/asio.hpp>
#include <boost/multi_index_container.hpp>
#include <boost/multi_index/ordered_index.hpp>
#include <boost/multi_index/member.hpp>
#include <boost/utility/result_of.hpp>

template <typename Priority,
		  typename Compare = std::less<Priority> >
class Scheduler
{

public:

	typedef Priority priority_type;
	typedef boost::mutex mutex_type;

private:

	struct method_request
	{
		typedef boost::function<bool()> ready_func_type;
		typedef boost::function<void()> run_func_type;

		template< typename ReadyFunctor,
				  typename RunFunctor >
		method_request( ReadyFunctor ready,
						RunFunctor run )
			: ready_( ready ),
			  run_( run )
		{};

		ready_func_type ready_;
		run_func_type run_;

	};

	typedef std::pair< priority_type, boost::shared_ptr<method_request> > pair_type;

	static bool is_method_ready( const pair_type& pair )
	{
		return pair.second->ready();
	}

	static bool always_ready() 
	{
		return true;
	}

public:

	Scheduler( std::size_t maxThreads, std::size_t maxRequests )
		:	work_( ioService_ ),
			maxRequests_( maxRequests ),
			requestCount_( 0 )
	{
		for( std::size_t i = 0; i < maxThreads; ++i )
		{
			threads_.create_thread( boost::bind( &boost::asio::io_service::run, &ioService_ ) );
		}
	}

	~Scheduler()
	{
		ioService_.stop();
		threads_.join_all();
	}

	template< 	typename ReadyFunctor,
				typename RunFunctor >
		boost::unique_future< typename boost::result_of< RunFunctor() >::type >
	Insert( 	priority_type priority,
				const ReadyFunctor& ready_function,
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

		boost::shared_ptr< method_request > request =
			boost::make_shared< method_request >( ready_function, boost::bind( &task_type::operator(), request ) );

		activationList_.insert( activationList_.end(), pair_type( priority, request ) );

		ioService_.post( boost::bind( &Scheduler::Dispatch, this ) );

		return task->get_future();

	}

#if 0
	template< typename ReadyFunctor, typename RunFunc >
		boost::unique_future< typename boost::result_of<RunFunctor()>::type>
	Insert( priority_type priority, const ReadyFunctor& ready_function, const RunFunctor& run_function )
	{
		return Insert( priority_type(), ready_function, run_function );
	}

	template< typename RunFunctor >
		boost::unique_future< typename boost::result_of<RunFunctor()>::type>
	Insert( priority_type priority, const RunFunctor& run_function )
	{
		return Insert( priority, &always_ready, run_function );
	}

	template< typename RunFunctor >
		boost::unique_future< typename boost::result_of<RunFunctor()>::type>
	Insert( const RunFunctor& run_function )
	{
		return Insert( &always_ready, run_function );
	}
#endif

	void Cancel()
	{
		boost::unique_lock<mutex_type> lock( mutex_ );
		activationList_.clear();
		requestCount_ = 0;
	}

private:

	void Dispatch()
	{
		boost::unique_lock<mutex_type> lock( mutex_ );

		if( activationList_.empty() )
		{
			return;
		}

		typedef typename activation_list_type::iterator iterator;
		iterator end = activationList_.end();
		iterator result = std::find_if( activationList_.begin(), end, &is_method_ready );

		if( end == result )
		{
			ioService_post( boost::bind( &Scheduler::Dispatch, this ) );
			return;
		}

		boost::shared_ptr< method_request > method = result->second;
		activationList_.erase( result );

		lock.unlock();
		method->run();
		lock.lock();

		--requestCount_;
	}

	typedef boost::multi_index_container<
		pair_type,
		boost::multi_index::indexed_by<
			boost::multi_index::ordered_non_unique<
				boost::multi_index::member< pair_type,
											typename pair_type::first_type,
											&pair_type::first >,
				Compare
			>
		>
	> activation_list_type;

	activation_list_type	activationList_;

	boost::thread_group threads_;

	boost::asio::io_service ioService_;
	boost::asio::io_service::work work_;

	std::size_t maxRequests_;
	std::size_t requestCount_;

	mutex_type mutex_;

};

typedef Scheduler< unsigned int, std::greater< unsigned int > > priority_scheduler;
 
#endif

