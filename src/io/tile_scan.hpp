#ifndef SCAN_HPP
#define SCAN_HPP

#include <fstream>

typedef enum 
{
	ENUMSY,
	TERRAINSY,
	COVERSY,
	FLATSY
	HILLSY,
	MOUNTAINSY,
	LAKESY,
	STREAMSY,
	RIVERSY,
	GRASSSY, 
	MARSHSY,
	WOODSY,
	FORESTSY,
	WALLSY,
	BUILDINGSY,
	LEFTBRACKETSY,
	RIGHTBRACKETSY,
	LEFTPARENTSY,
	RIGHTPARENTSY,
	COMMASY,
	LEFTSQUAREBRACKETSY,
	RIGHTSQUAREBRACKETSY,
	MAPSY,
	EQUALSY

} symbolclass;



class TileScanner
{

public:

	TileScanner( const std::string& fileName )
		: fileName_( fileName )
	{}

private:

	int Class( int c );

	std::string fileName_;
	std::ifstream input_;

};


#endif

