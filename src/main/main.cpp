#include <iostream>
#include <string>

#include <ncurses.h>

WINDOW* create_win( int height, int width, int starty, int startx );
void destroy_win( WINDOW* local_win );

int main( int argc, char** argv )
{
//	WINDOW* win;
	int startx, starty, width, height;
//	int ch;
	int row, col;

	char  prompt[] = "Enter command: ";
	char  cmd[80];

    initscr();
	raw();
	keypad(stdscr, TRUE);
//	noecho();
	getmaxyx( stdscr, row, col );

	height = 10;
	width = 10;
	starty = (LINES - height) / 2;
	startx = (COLS - width) / 2;

	printw("press F2 to exit");

    refresh();

//	win = create_win( height, width, starty, startx );
	create_win( height, width, starty, startx );
	mvprintw( row-1, 0, "%s", prompt );
	getstr( cmd );
	mvprintw( 0, 0, "Command: %s", cmd );
	getch();
  
#if 0
	while(( ch = getch() ) != KEY_F(2))
	{
		switch( ch )
		{
			case KEY_LEFT:	
				destroy_win( win );
				win = create_win( height, width, starty, --startx );
				break;
			case KEY_RIGHT:
				destroy_win( win );
				win = create_win( height, width, starty, ++startx );
				break;
			case KEY_UP:
				destroy_win( win );
				win = create_win( height, width, --starty, startx );
				break;
			case KEY_DOWN:
				destroy_win( win );
				win = create_win( height, width, ++starty, startx );
				break;	
		}
	}
#endif

    endwin();

    return 0;
}

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
