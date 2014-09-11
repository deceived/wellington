#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include <boost/smart_ptr.hpp>

class Actor;
class ActorComponent;

typedef boost::shared_ptr<Actor>    ActorPtr;
typedef boost::shared_ptr<ActorComponent>   ActorComponentPtr;

typedef unsigned long ActorId;
typedef unsigned long ActorComponentId;

#endif

