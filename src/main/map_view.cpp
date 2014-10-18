#include "map_view.hpp"

void MapView::Put( unsigned int row, unsigned int col, MapView::line_ptr line )
{
	mvprintw( row, col, (*line).c_str() );
}

void MapView::Put( unsigned int row, unsigned int col, char ch )
{
}

