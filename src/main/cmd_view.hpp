#ifndef CMD_VIEW_HPP
#define CMD_VIEW_HPP

#include <ncurses.h>

#include <string>

#include <boost/smart_ptr.hpp>

class CmdView
{
	
public:

	typedef boost::shared_ptr< std::string > line_ptr;

	void Put( unsigned int row, unsigned int col, CmdView::line_ptr line );
	void ClearLine( unsigned int row, unsigned int col, unsigned int length );
	std::string Read( unsigned int row, unsigned int col );

};

#endif

