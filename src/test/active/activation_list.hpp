#ifndef ACTIVATION_LIST_HPP
#define ACTIVATION_LIST_HPP

#include <cstddef>
#include <list>

#include <boost/date_time/posix_time/posix_time.hpp>

#include "request.hpp"

class ActivationList
{

public:

	typedef std::list< boost::shared_ptr< MethodRequest > > activation_data;
	typedef boost::shared_ptr< boost::posix_time::time_duration> > timeout_ptr;

	enum { INFINITE = -1 };

	typedef ActivationListIterator iterator;

	ActivationList( std::size_t high_water_mark );

	void Insert( Request::request_ptr request, timeout_ptr timeout = 0 );

	void Remove( Request::request_ptr request, timeout_ptr timeout = 0 );

private:

	std::size_t	high_water_mark_;

	activation_data activation_list_;
 
};

#endif

