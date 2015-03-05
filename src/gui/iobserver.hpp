#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include <boost/smart_ptr.hpp>

class IObserver
{

public:

	typedef boost::shared_ptr< IObserver > observer_ptr;

	virtual void Register( observer_ptr observer ) = 0;
	virtual void Unregister( observer_ptr observer ) = 0;

	virtual void Notify() = 0;

};

#endif

