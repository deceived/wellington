#ifndef TILE_HPP
#define TILE_HPP

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

    Tile( unsigned int id, terrain_t terrain, cover_t cover, Point& location )
      : id_( id ),
        terrain_( terrain ),
		cover_( cover ),
        location_( location )
    {}

    int GetX()
    {
        return location_.GetX();
    }

    int GetY()
    {
        return location_.GetY();
    }

    enum terrain_t GetTerrain()
    {
        return terrain_;
    }

    enum cover_t GetCover()
    {
        return cover_;
    }

private:

    unsigned int id_;

    enum terrain_t terrain_;
    enum cover_t cover_;

    Point location_;

};

#endif
