#include "stdscr_model.hpp"


line_ptr StdScrModel::GetPrompt()
{
	return boost::make_shared<std::string>( "Enter command: " );
}


map_ptr	StdScrModel::GetMap()
{
	return map_;
}

key_ptr	StdScrModel::GetKey()
{
	return key_;
}

cmd_ptr	StdScrModel::GetCmd()
{
	return cmd_;
}


