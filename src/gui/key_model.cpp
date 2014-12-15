#include "key_model.hpp"


void KeyModel::Load( std::string fileName )
{
	key_->Load( fileName );
}

size_t KeyModel::LineCount()
{
	return key_->GetRows();
}

KeyModel::line_ptr KeyModel::NextLine( size_t line )
{
	return key_->GetRow( line );
}

