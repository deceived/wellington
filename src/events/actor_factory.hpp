#ifndef ACTOR_FACTORY_HPP
#define ACTOR_FACTORY_HPP

#include <boost/smart_ptr.hpp>
#include <boost/utility.hpp>
#include <boost/foreach.hpp>
#include <boost/property_tree/ptree.hpp>

#include "actor.hpp"
#include "actor_component.hpp"
#include "properties.hpp"



class   ActorFactory : public boost::noncopyable
{

public:

#if 0
    typedef boost::shared_ptr<ActorComponent> ActorComponent::ptr;

    typedef boost::shared_ptr<ActorComponent> (*ActorComponentCreator)();
    typedef std::map< std::string, ActorComponentCreator > ActorComponentCreatorMap;
#endif

    ActorFactory() { std::cout << "ctor()" << "\n"; }

    Actor::ptr    CreateActor( const std::string& actorResource );

private:

    Actor::Id   GetNextId() {}

    virtual ActorComponent::ptr CreateComponent( boost::property_tree::ptree& data );

//    ActorComponentCreatorMap    actorComponentCreators_;

    Actor::Id   id_;

};

#endif

