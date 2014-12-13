#ifndef CMD_MODEL_HPP
#define CMD_MODEL_HPP

#include <string>

#include <boost/smart_ptr.hpp>

class CmdModel
{

public:

	typedef boost::shared_ptr< std::string > line_ptr;

	CmdModel()
	{}

	CmdModel::line_ptr  GetPrompt();

private:

};

#endif

