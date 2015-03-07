#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <boost/smart_ptr.hpp>

class Request
{

public:

	typedef boost::shared_ptr< Request > request_ptr;

	virtual void CanRun() const = 0;
	virtual void Call() = 0;

};

class MoveRequest : public Request
{

public:

	Move( Servant* rep, const Future& future )
		: servant_( rep ),
		  result_( future )
	{}

	virtual bool CanRun() const
	{
		return true;
	}

	virtual void Call()
	{
		result_ = servant_->Move();
	}

private:

	Servant* servant_;
	Future result_;

};

#endif
