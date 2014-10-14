#include "stdscr_view.hpp"

StdScrView::StdScrView()
{
	initscr();
	raw();
	keypad( stdscr, TRUE );
	getmaxyx( rows_, columns_ );
	refresh();
}

StdScrView::~StdScrView()
{
	endwin();
}

void StdScrView::DisplayLine( unsigned int row, unsigned int column, std::string& line )
{
	mvprintw( row, column, line.c_str() );
}

void StdScrView::ClearLine( unsigned int row, unsigned int column, int length )
{
	for(unsigned int count = 0; count < length; ++count)
	{
		mvaddch( row, column, ' ' );
	} 
}

