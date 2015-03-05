#ifndef SERVANT_HPP
#define SERVANT_HPP

class Servant
{

public:

	Servant( size_t size );
	~Servant();

	void Put( const Message& message );
	Message Get();

	bool Empty() const;
	bool Full() const;

private:

};

#endif

