#ifndef MAP_VIEW_HPP
#define MAP_VIEW_HPP

#include <string>

class MapView
{
	
public:

	void Put( unsigned int row, unsigned int col, std::string line );
	void Put( unsigned int row, unsigned int col, char ch );

};

#endif
