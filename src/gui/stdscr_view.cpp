#include "stdscr_view.hpp"
#include <iostream>
StdScrView::StdScrView()
	:
		rows_( LINES ),
		columns_( COLS )
{
}

StdScrView::~StdScrView()
{
	Terminate();
}

void StdScrView::Init()
{
	initscr();
	raw();
	keypad( stdscr, TRUE );
	//int rows, cols;
	//getmaxyx( stdscr, rows, cols );
	//rows_ = rows;
	//columns_ = cols;
	refresh();
}

void StdScrView::Terminate()
{
	endwin();
}

void StdScrView::DisplayLine( unsigned int row, unsigned int column, std::string& line )
{
	mvprintw( row, column, line.c_str() );
}

void StdScrView::Put( unsigned int row, unsigned int col, line_ptr line )
{
	mvprintw( row, col, (*line).c_str() );
}

StdScrView::line_ptr StdScrView::Read( unsigned int row, unsigned int col )
{
	char cmd[ 128 ];

	move( row, col );
	getstr( cmd );

	return boost::make_shared<std::string>( cmd );
}

StdScrView::line_ptr StdScrView::Read()
{
	char cmd[ 128 ];

	getstr( cmd );

	return boost::make_shared<std::string>( cmd );
}

void StdScrView::ClearLine( unsigned int row, unsigned int column, unsigned int length )
{
	for(unsigned int count = 0; count < length; ++count)
	{
		mvaddch( row, column + count, ' ' );
	} 
}

void StdScrView::Put( unsigned int row, unsigned int col, char ch )
{
}

