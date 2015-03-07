#ifndef REQUEST_HPP
#define REQUEST_HPP

class Request
{

public:

	virtual void CanRun() const = 0;
	virtual void Call() = 0;

};

class Move : public Request
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
