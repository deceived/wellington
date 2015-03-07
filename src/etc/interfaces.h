#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include <boost/smart_ptr.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

class Actor;
class ActorComponent;

typedef boost::shared_ptr<Actor>    ActorPtr;
typedef boost::shared_ptr<ActorComponent>   ActorComponentPtr;
typedef boost::shared_ptr< boost::posix_time::time_duration >  timeout_ptr;

//typedef unsigned long ActorId;
//typedef unsigned long ActorComponentId;

typedef std::size_t ActorId;
typedef std::size_t ComponentId;

#endif

