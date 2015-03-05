#ifndef IOBSERVER_HPP
#define IOBSERVER_HPP

#include <boost/smart_ptr.hpp>

class IObserver
{

public:

	typedef boost::shared_ptr< IObserver > observer_ptr;

	void Register( observer_ptr observer ) = 0;
	void Unregister( observer_ptr observer ) = 0;

	void Notify() = 0;

};

#endif

