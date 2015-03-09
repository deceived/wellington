#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

#include <cstddef>

#include <boost/thread.hpp>

#include "request.hpp"

class Run
{

public:

	void operator()() {}
};

class Scheduler
{

public:

	Scheduler( size_t high_water_mark );

	void Insert( Request::request_ptr request );

	virtual void Dispatch();

private:

	//ActivationList activationList_;

	//static void Run();

	boost::thread thread_;

};

#endif

