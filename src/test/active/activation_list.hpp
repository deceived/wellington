#ifndef ACTIVATION_LIST_HPP
#define ACTIVATION_LIST_HPP

class ActivationList
{

public:

	enum { INFINITE = -1 };

	typedef ActivationListIterator iterator;

	ActivationList( size_t high_water_mark );

	void Insert( MethodRequest* request, TimeValue* timeout = 0 );

	void Remove( MethodRequest*& request, TimeValue* timeout = 0 );

private:

};

#endif

