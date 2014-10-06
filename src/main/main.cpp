#include <iostream>
#include <string>

#include <ncurses.h>

#include "ncwindow.hpp"

WINDOW* create_win( int height, int width, int starty, int startx );
void destroy_win( WINDOW* local_win );

int main( int argc, char** argv )
{
#if 0
	WINDOW* win;
	int startx, starty, width, height;
	int ch;

    initscr();
    cbreak();

	height = 20;
	width = 30;
	starty = (LINES - height);
	startx = (COLS - width);

    refresh();
	win = create_win( height, width, starty, startx );

    getch();
    endwin();
#endif

	int height = 20;
	int width = 30;

    Window* w = new Window( height, width, (LINES - height), (COLS - width) );
   
    delete w;
 
    return 0;
}

#if 0
WINDOW* create_win( int height, int width, int starty, int startx )
{	
    WINDOW* win;

	win = newwin( height, width, starty, startx );
	box( win, 0 , 0 );
	wrefresh( win );

	return win;
}


void destroy_win(WINDOW* local_win)
{	
	wborder(local_win, ' ', ' ', ' ',' ',' ',' ',' ',' ');
	wrefresh(local_win);
	delwin(local_win);
}
#endif
