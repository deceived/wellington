#ifndef KEY_VIEW_HPP
#define KEY_VIEW_HPP

#include <ncurses.h>

#include <string>

#include <boost/smart_ptr.hpp>

class KeyView
{
	
public:

	typedef boost::shared_ptr< std::string > line_ptr;

	void Put( unsigned int row, unsigned int col, KeyView::line_ptr line );
	void Put( unsigned int row, unsigned int col, char ch );

};

#endif

