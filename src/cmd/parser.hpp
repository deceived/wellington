#ifndef PARSER_HPP
#define PARSER_HPP

#include "driver.hpp"

namespace order
{

class	Parser
{

public:

	Parser( class Driver& driver )
		: driver_( driver )
	{}

private:

	Driver&	driver_;

};

}

#endif

