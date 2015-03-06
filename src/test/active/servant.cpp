#include "servant.hpp"


Servant::Servant( std::size_t size )
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
	return false;
}

bool Servant::Full() const
{
	return false;
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

