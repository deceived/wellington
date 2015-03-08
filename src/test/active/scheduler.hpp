#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <cstddef>

#include "request.hpp"

class Scheduler
{

public:

	Scheduler( size_t high_water_mark );

	void Insert( Request::request_ptr request );

	virtual void Dispatch();

private:

	//ActivationList activationList_;

	static void* Run( void* args );

};

#endif

