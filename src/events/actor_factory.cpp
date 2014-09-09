#include "actor_factory.hpp"
#include "identity_component.hpp"

ActorFactory::ActorFactory()
{
    componentFactory_.Register< IdentityComponent >( ActorComponent::GetIdFromName( "IdentityComponent" ) );
#if 0
    componentFactory_.Register< SpriteComponent >( ActorComponent::GetIdFromName( "SpriteComponent" ) );
    componentFactory_.Register< IdentityComponent >( ActorComponent::GetIdFromName( "IdentityComponent" ) );
    componentFactory_.Register< MoveComponent >( ActorComponent::GetIdFromName( "MoveComponent" ) );
    componentFactory_.Register< FightComponent >( ActorComponent::GetIdFromName( "FightComponent" ) );
    componentFactory_.Register< OrderComponent >( ActorComponent::GetIdFromName( "OrderComponent" ) );
    componentFactory_.Register< ReactionComponent >( ActorComponent::GetIdFromName( "ReactionComponent" ) );
    componentFactory_.Register< AIComponent >( ActorComponent::GetIdFromName( "AIComponent" ) );
#endif
}

Actor::ptr    ActorFactory::CreateActor( const std::string& actorResource )
{
    Properties::ptr resource = Properties::ReadXml( actorResource );
    if( !resource )
    {
        return Actor::ptr();
    }

    Actor::ptr actor = boost::make_shared<Actor>( GetNextId() );

    if( !actor->Init( resource ) )
    {
        return Actor::ptr();
    }   
#if 0
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
            return Actor::ptr();
        } 
    }

    actor->PostInit();
#endif

    return actor;
}

ActorComponent::ptr ActorFactory::CreateComponent( Properties::ptr data )
{
    std::string name( data->data() );

    ActorComponent::ptr   component;

#if 0
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

    return boost::make_shared< ActorComponent >();
}


