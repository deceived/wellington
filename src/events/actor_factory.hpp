#ifndef ACTOR_FACTORY_HPP
#define ACTOR_FACTORY_HPP

#include <boost/smart_ptr.hpp>
#include <boost/utility.hpp>
#include <boost/foreach.hpp>

#include "actor.hpp"
#include "actor_component.hpp"
#include "properties.hpp"



class   ActorFactory : public boost::noncopyable
{

public:

    typedef boost::shared_ptr<ActorComponent> (*ActorComponentCreator)();
    typedef std::map< std::string, ActorComponentCreator > ActorComponentCreatorMap;

    ActorFactory() 
        : id_( 0 )
    {}

    Actor::ptr    CreateActor( const std::string& actorResource );

private:

    Actor::Id   GetNextId() 
    {
        ++id_;
        return id_;
    }

    virtual ActorComponent::ptr CreateComponent( Properties::ptr data );

    ActorComponentCreatorMap    actorComponentCreators_;

    Actor::Id   id_;
};

#endif

