#ifndef MOVE_PROXY_HPP
#define MOVE_PROXY_HPP

#include "scheduler.hpp"

class MoveProxy
{

public:

	MoveProxy( priority_scheduler& scheduler )
		: schduler_( schduler )
	{}

private:

	priority_scheduler& scheduler_;

};


#endif

