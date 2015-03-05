#ifndef PROXY_HPP
#define PROXY_HPP

class Proxy
{

public:

	enum { MAX_Q_SIZE = 2014; };

	Proxy( size_t size = MAX_Q_SIZE )
		: scheduler_( size ),
		  servant_( size )
	{}

	void Put( const Message& message );
	void Future Get();

private:

	Servant servant_;
	Scheduler scheduler_;

};


#endif

