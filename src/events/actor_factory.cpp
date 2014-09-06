#include "actor_factory.hpp"



Actor::ptr    ActorFactory::CreateActor( const std::string& actorResource )
{

#if 0
    Properties   component( actorResource );
    
    Properties::ptr root = component.Get();
    if( !root )
    {
        return ActorPtr();
    }

    ActorPtr actor = boost::make_shared<Actor>( GetNextId() );

    if( !actor->Init( root ) )
    {
        return ActorPtr();
    }   

    BOOST_FOREACH( boost::property_map::ptree::value_type& v, 
                    *root.get_child( "Actor" ))
    {
        ActorComponentPtr component( CreateComponent( v.second ) );
        if( component )
        {
            actor->AddComponent( component );
            component->SetOwner( actor );
        }
        else
        {
            return ActorPtr();
        } 
    }

    actor->PostInit();
#endif

    Actor::ptr actor = boost::make_shared<Actor>( GetNextId() );

    return actor;
}

ActorComponent::ptr ActorFactory::CreateComponent( boost::property_tree::ptree& data )
{

#if 0
    std::string name( data.data() );

    ActorComponentPtr   component;

    auto it = ActorComponentCreators.find( name );
    if( it != ActorComponentCreators.end() )
    {
        ActorComponentCreator creator = it->second;
        component.reset( creator );
    }
    else
    {
        return ActorComponentCreator();
    }

    if( component )
    {
        if( !component->Init( data ) )
        {
            return ActorComponentCreator();
        }
    }

    return component;
#endif
}


