#ifndef TYPES_HPP
#define TYPES_HPP

#include <string>

#include <boost/smart_ptr.hpp>

#include "cmd.hpp"

typedef boost::shared_ptr< std::string >	line_ptr;
typedef boost::shared_ptr< Command > cmd_ptr;

#endif

