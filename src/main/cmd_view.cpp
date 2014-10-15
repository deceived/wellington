#include "cmd_view.hpp"

void CmdView::Put( unsigned int row, unsigned int col, std::string line )
{
	mvprintw( row, col, line.c_str() );
}

std::string CmdView::Read( unsigned int row, unsigned int col )
{
	char cmd[ 128 ];

	move( row, col );
	getstr( cmd );

	return std::string( cmd );
}

void CmdView::ClearLine( unsigned int row, unsigned int column, int length )
{
	for(unsigned int count = 0; count < length; ++count)
	{
		mvaddch( row, column, ' ' );
	} 
}

