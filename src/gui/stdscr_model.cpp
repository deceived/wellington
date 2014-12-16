#include "stdscr_model.hpp"


line_ptr StdScrModel::GetPrompt()
{
	return boost::make_shared<std::string>( "Enter command: " );
}


map_ptr	StdScrModel::GetMap()
{
	return map_;
}



