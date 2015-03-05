#ifndef REQUEST_HPP
#define REQUEST_HPP

class Request
{

public:

	virtual void CanRun() const = 0;
	virtual void Call() = 0;

};

class Get : public Request
{

public:

	Get( Servant* rep, const Future& future )
		: servant_( rep ),
		  result_( future )
	{}

	virtual bool CanRun() const;
	virtual void Call();

private:

	Servant* servant_;
	Future result_;

};

class Put : public Request
{

public:

	Put( Servant* rep, const Future& future )
		: servant_( rep ),
		  result_( future )
	{}

	virtual bool CanRun() const;
	virtual void Call();

private:

	Servant* servant_;
	Future result_;

};

#endif
