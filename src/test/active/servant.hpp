#ifndef SERVANT_HPP
#define SERVANT_HPP

#include <cstddef>

#include "message.hpp"

class Servant
{

public:

	Servant( std::size_t size );
	~Servant();

	void Put( const Message& message );
	Message Get();

	bool Empty() const;
	bool Full() const;

	void Move();
	void Fight();
	void Command();

private:

};

#endif

