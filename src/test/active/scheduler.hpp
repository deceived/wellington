#ifndef SCHEDULER_HPP
#define SCHEDULER_HPP

class Scheduler
{

public:

	Scheduler( size_t high_water_mark );

	void Insert( MethodRequest* request );

	virtual void Dispatch();

private:

	ActivationList activationList_;

	static void* Run( void* args );

};

#endif

