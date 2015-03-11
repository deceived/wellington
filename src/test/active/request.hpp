#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <boost/smart_ptr.hpp>
#include <boost/function.hpp>

#include "servant.hpp"
#include "future.hpp"

class Request
{

public:

	typedef boost::shared_ptr< Request > request_ptr;

	typedef boost::function<bool()> ready_function_type;
	typedef boost::function<void()> run_function_type;

	template <  typename ReadyFunctor,
				typename RunFunctor >
	Request( ReadyFunctor ready, RunFunctor run )
		: ready_( ready ),
		  run_( run )
	{}

	//virtual bool CanRun() const = 0;
	//virtual void Call() = 0;

	ready_function_type	ready_;
	run_function_type run_;

};

#if 0 

class MoveRequest : public Request
{

public:

	typedef boost::shared_ptr< MoveRequest > move_request_ptr;

	MoveRequest( Servant::servant_ptr rep, Future::future_ptr future )
		: servant_( rep ),
		  result_( future )
	{}

	virtual bool CanRun() const
	{
		return true;
	}

	virtual void Call()
	{
		//result_ = servant_->Move();
	}

private:

	Servant::servant_ptr servant_;
	Future::future_ptr result_;

};
#endif

#endif
