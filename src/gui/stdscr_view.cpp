#include "stdscr_view.hpp"
#include <iostream>
StdScrView::StdScrView()
	: 	mapView_( boost::make_shared< MapView >() ),
		keyView_( boost::make_shared< KeyView >() ),
		cmdView_( boost::make_shared< CmdView >() ),
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

void StdScrView::ClearLine( unsigned int row, unsigned int column, int length )
{
	for(int count = 0; count < length; ++count)
	{
		mvaddch( row, column, ' ' );
	} 
}

