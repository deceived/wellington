#ifndef SERVANT_HPP
#define SERVANT_HPP

#include <boost/smart_ptr.hpp>

class Servant
{

public:

	typedef boost::shared_ptr< Servant > servant_ptr;

	Servant();
	~Servant();

	void Move();

private:

};

#endif

