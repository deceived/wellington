#include "key_view.hpp"

void KeyView::Put( unsigned int row, unsigned int col, KeyView::line_ptr line )
{
	mvprintw( row, col, (*line).c_str() );
}


