#ifndef ACTOR_FACTORY_HPP
#define ACTOR_FACTORY_HPP

#include <map>

#include <boost/smart_ptr.hpp>
#include <boost/utility.hpp>
#include <boost/foreach.hpp>

#include "actor.hpp"
#include "actor_component.hpp"
#include "properties.hpp"




template <class BaseType, class SubType>
BaseType* GenericObjectCreationFunction(void) 
{ 
    return new SubType; 
}

template <class BaseClass, class IdType>
class GenericObjectFactory
{
    typedef BaseClass* (*ObjectCreationFunction)(void);

public:

    template <class SubClass>
    bool Register( IdType id )
    {
        auto it = creationFunctions.find( id );
        if ( it == creationFunctions.end() )
        {
            creationFunctions[ id ] = &GenericObjectCreationFunction< BaseClass, SubClass >;
            return true;
        }

        return false;
    }

    BaseClass* Create( IdType id )
    {
        auto it = creationFunctions.find( id );
        if( it != creationFunctions.end() )
        {
            ObjectCreationFunction func = it->second;
            return func();
        }

        return NULL;
    }

private:

    std::map< IdType, ObjectCreationFunction > creationFunctions;

};


class   ActorFactory : public boost::noncopyable
{

public:

    typedef boost::shared_ptr<ActorComponent> (*ActorComponentCreator)();
    typedef std::map< std::string, ActorComponentCreator > ActorComponentCreatorMap;

    ActorFactory();

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

