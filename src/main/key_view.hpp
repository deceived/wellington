#ifndef KEY_VIEW_HPP
#define KEY_VIEW_HPP

#include <string>

class KeyView
{
	
public:

	void Put( unsigned int row, unsigned int col, std::string line );
	void Put( unsigned int row, unsigned int col, char ch );

};

#endif

