#ifndef FUTURE_HPP
#define FUTURE_HPP

class Future
{

public:

	Future( const Future& future );
	Future( const Message& message );
	Future();

	void operator=( const Future& future );

	Message Result( TimeValue* timeout = 0) const;

private:

	FutureImplementation* implementation_;

};

#endif

