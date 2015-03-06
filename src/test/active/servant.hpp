#ifndef SERVANT_HPP
#define SERVANT_HPP

#include <cstddef>
#include <list>

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

	std::size_t	size_;

	std::list< Message > messages_;

};

#endif

