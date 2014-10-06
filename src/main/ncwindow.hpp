#ifndef NC_WINDOW_HPP
#define NC_WINDOW_HPP

#include   <ncurses.h>


class Window
{

public:

    Window( int lines, int cols, int startY, int startX )
        :   height_( lines ),
            width_( cols ),
            startY_( startY ),
            startX_( startX )
    {
        initscr();
        cbreak();
        refresh();

	    window_ = newwin( height_, width_, startY_, startX_ );
        box( window_, 0, 0 );
        wrefresh( window_ );

        getch();
        endwin();
    }

    virtual ~Window()
    {
	    wborder( window_, ' ', ' ', ' ',' ',' ',' ',' ',' ' );
	    wrefresh( window_ );
	    delwin( window_ );
    }

protected:

    int height_;
    int width_;
    int startY_;
    int startX_;

    WINDOW*        window_;

private:

};

#endif

