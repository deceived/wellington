#ifndef TILE_HPP
#define TILE_HPP

#include <vector>

class Point
{

public:

    Point()
      : x_( 0 ),
        y_( 0 )
    {}

    Point( int x, int y )
      : x_( x ),
        y_( y )
    {}

    void SetX( int x )
    {
		x_ = x;
    }

    int GetX()
    {
    	return x_;
    }

    void SetY( int y )
    {
		y_ = y;
    }

    int GetY()
    {
		return y_;
    }

private:

    int x_;
    int y_;

};



class Tile
{

public:

    enum terrain_t 
    {
	Flat,
        Hill,
        Mountain,
        Lake,
        Stream,
        River
    };

    enum cover_t
    {
        Grass,
        Marsh,
		Wood,
		Forest,
		Wall,
		Building
    };

    Tile( unsigned int id )
      : id_( id )
    {}

    int GetX()
    {
        return location_.GetX();
    }

    int GetY()
    {
        return location_.GetY();
    }

	void SetLocation( Point location )
	{
		location_ = location;
	}

    enum terrain_t GetTerrain()
    {
        return terrain_;
    }

	void SetTerrain( terrain_t terrain )
	{
		terrain_ = terrain;
	}
	
    std::vector<enum cover_t> GetCover()
    {
        return cover_;
    }

	void SetCover( cover_t cover )
	{
		cover_.push_back( cover );
	}

private:

    unsigned int id_;

    enum terrain_t terrain_;
	std::vector< enum cover_t> cover_;

    Point location_;

};

#endif
