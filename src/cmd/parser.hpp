#ifndef PARSER_HPP
#define PARSER_HPP

#include "driver.hpp"

class	Parser
{

public:

	Parser( class Driver& driver )
		: driver_( driver )
	{}

private:

	Driver&	driver_;

};

#endif

