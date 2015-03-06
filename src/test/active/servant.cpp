#include "servant.hpp"


Servant::Servant( std::size_t size )
	: size_( size )
{
}

Servant::~Servant()
{
}

void Servant::Put( const Message& message )
{
	messages_.push_back( message );
}

Message Servant::Get()
{
	return Message();
}

bool Servant::Empty() const
{
	return messages_.empty();
}

bool Servant::Full() const
{
	return messages_.size() < size_ ? false : true;
}

void Servant::Move()
{
}

void Servant::Fight()
{
}

void Servant::Command()
{
}

