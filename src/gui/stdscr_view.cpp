#include "stdscr_view.hpp"

#include <iostream>

StdScrView::StdScrView()
	:
		rows_( LINES ),
		columns_( COLS )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
}

StdScrView::~StdScrView()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	Terminate();
}

void StdScrView::Init()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
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
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	endwin();
}

void StdScrView::DisplayLine( unsigned int row, unsigned int column, std::string& line )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	mvprintw( row, column, line.c_str() );
}

void StdScrView::Put( unsigned int row, unsigned int col, line_ptr line )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	mvprintw( row, col, (*line).c_str() );
}

StdScrView::line_ptr StdScrView::Read( unsigned int row, unsigned int col )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	char cmd[ 128 ];

	move( row, col );
	getstr( cmd );

	return boost::make_shared<std::string>( cmd );
}

StdScrView::line_ptr StdScrView::Read()
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	char cmd[ 128 ];

	getstr( cmd );

	return boost::make_shared<std::string>( cmd );
}

void StdScrView::ClearLine( unsigned int row, unsigned int column, unsigned int length )
{
	logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
	for(unsigned int count = 0; count < length; ++count)
	{
		mvaddch( row, column + count, ' ' );
	} 
}

void StdScrView::Put( unsigned int row, unsigned int col, char ch )
{
	mvaddch( row, col, ch );
}

