#ifndef ADD_PROXY_HPP
#define ADD_PROXY_HPP

#include "scheduler.hpp"

class AddProxy
{

public:

	AddProxy( priority_scheduler& scheduler )
		: scheduler_( scheduler )
	{}


	template< typename T >
		boost::unique_future<T> Add(
			priority_scheduler::priority_type priority,
			const T& a, const T& b )
	{
		return scheduler_.Insert( priority, 
					boost::bind( &AddProxy::DoAdd<T>, a, b ) );
	}

	template< typename T >
		boost::unique_future<T> Add( const T& a, const T& b )
	{
		return Add( priority_scheduler::priority_type(), a, b );
	}

private:

	template< typename T >
		static T DoAdd( const T& a, const T& b )
	{
		std::cout << "start adding " << a << " and " << b << std::endl;
		boost::this_thread::sleep_for( boost::chrono::seconds( 2 ) );
		std::cout << "finished adding" << std::endl;
		return a + b;
	}
	

	priority_scheduler& scheduler_;

};

#endif
