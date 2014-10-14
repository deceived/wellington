#ifndef STDSCR_VIEW_HPP
#define STDSCR_VIEW_HPP

#include <string>

class StdScrView
{

public:

	StdScrView();
	~StdScrView();

	void DisplayLine( int row, int column, std::string& line );
	void ClearLine( int row, int column, int length );

private:

	int rows_;
	int columns_;
};


#endif

