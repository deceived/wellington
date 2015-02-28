#ifndef STDSCR_VIEW_HPP
#define STDSCR_VIEW_HPP

#include <ncurses.h>

#include <string>

#include <boost/smart_ptr.hpp>

#include "logger.hpp"

extern Log logger;

class StdScrView
{

public:

	typedef boost::shared_ptr< StdScrView > view_ptr;

	typedef boost::shared_ptr< std::string > line_ptr;

	StdScrView();
	~StdScrView();

	void Init();
	void Terminate();

	
	void Display();

	void DisplayMap();
	void DisplayKey();
	void DisplayCommand();
	void DisplayUnits();

	void DisplayLine( unsigned int row, unsigned int column, std::string& line );

	void Put( unsigned int row, unsigned int col, line_ptr line );
	void Put( unsigned int row, unsigned int col, char ch );

	void ClearLine( unsigned int row, unsigned int col, unsigned int length );

	line_ptr Read( unsigned int row, unsigned int col );
	line_ptr Read();

private:

	int rows_;
	int columns_;
};


#endif
