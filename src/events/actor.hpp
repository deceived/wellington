#ifndef ACTOR_HPP
#define ACTOR_HPP

#include <map>

#include <boost/property_tree/ptree.hpp>

#include "properties.hpp"

class   Actor
{

public:

    typedef unsigned long Id;
    typedef boost::shared_ptr< Actor > ptr;

//    typedef std::map< Component::Id, ActorComponent::Ptr > ActorComponents;

    explicit Actor( Id id )
    {
        actorId_ = id;
    }

    ~Actor() {};

    bool Init( Properties::ptr data ) {}
    void PostInit();
    void Destroy();

    void Update( int deltaMs );

    Actor::Id   GetId()
    {
        return actorId_;
    }

#if 0
    template< class ComponentType >
    boost::weak_ptr<ComponentType> GetComponent( Component::Id id )
    {
        ActorComponents::iterator it = components_.find( id );
        if( it != components_.end() )
        {
            ActorComponent::Ptr base( it->second );
            boost::shared_ptr< ComponentType > sub( std::static_ptr_cast<ComponentType>( base ) );
            boost::weak_ptr<ComponentType > weakSub( sub );
            return weakSub;
        }
        else
        {
            return boost::weak_ptr<ComponentType>();
        }
    }

    template <class ComponentType>
    boost::weak_ptr<ComponentType> GetComponent(const std::string& name)
    {
		Component::Id id = ActorComponent::GetIdFromName(name);
        ActorComponents::iterator it = components_.find( id );
        if( it != components_.end())
        {
            ActorComponent::Ptr base( it->second );
            boost::shared_ptr<ComponentType> sub( std::static_pointer_cast<ComponentType>( base ) );  
            boost::weak_ptr<ComponentType> weakSub( sub );  
            return weakSub;  
        }
        else
        {
            return boost::weak_ptr<ComponentType>();
        }
    }
#endif

private:

//    void AddComponent( ActorComponent::Ptr component );

    Id actorId_;

//    ActorComponents components_;

};

#endif

