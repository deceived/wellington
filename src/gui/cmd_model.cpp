#include "cmd_model.hpp"


CmdModel::line_ptr CmdModel::GetPrompt()
{
	return boost::make_shared<std::string>( "Enter command: " );
}

