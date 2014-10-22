#ifndef MAP_VIEW_HPP
#define MAP_VIEW_HPP

#include <ncurses.h>

#include <string>

#include <boost/smart_ptr.hpp>

class MapView
{
	
public:

	typedef boost::shared_ptr< std::string > line_ptr;

	void Put( unsigned int row, unsigned int col, MapView::line_ptr line );
	void Put( unsigned int row, unsigned int col, char ch );

};

#endif

