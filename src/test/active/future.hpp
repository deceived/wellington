#ifndef FUTURE_HPP
#define FUTURE_HPP

#include <boost/smart_ptr.hpp>

class Future
{

public:

	typedef boost::shared_ptr< Future > future_ptr;

	Future( future_ptr future );
//	Future( const Message& message );
	Future();

	void operator=( future_ptr future );

//	Message Result( TimeValue* timeout = 0) const;

private:

//	FutureImplementation* implementation_;

};

#endif

