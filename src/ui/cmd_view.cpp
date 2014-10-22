#include "cmd_view.hpp"

void CmdView::Put( unsigned int row, unsigned int col, CmdView::line_ptr line )
{
	mvprintw( row, col, (*line).c_str() );
}

CmdView::line_ptr CmdView::Read( unsigned int row, unsigned int col )
{
	char cmd[ 128 ];

	move( row, col );
	getstr( cmd );

	return boost::make_shared<std::string>( cmd );
}

CmdView::line_ptr CmdView::Read()
{
	char cmd[ 128 ];

	getstr( cmd );

	return boost::make_shared<std::string>( cmd );
}

void CmdView::ClearLine( unsigned int row, unsigned int column, unsigned int length )
{
	for(unsigned int count = 0; count < length; ++count)
	{
		mvaddch( row, column + count, ' ' );
	} 
}

