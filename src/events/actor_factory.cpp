#include "actor_factory.hpp"

#include "ai_component.hpp"
#include "fight_component.hpp"
#include "identity_component.hpp"
#include "move_component.hpp"
#include "order_component.hpp"
#include "reaction_component.hpp"
#include "sprite_component.hpp"

ActorFactory::ActorFactory()
{
    componentFactory_.Register< IdentityComponent >( ActorComponent::GetIdFromName( "IdentityComponent" ) );
    componentFactory_.Register< SpriteComponent >( ActorComponent::GetIdFromName( "SpriteComponent" ) );
    componentFactory_.Register< MoveComponent >( ActorComponent::GetIdFromName( "MoveComponent" ) );
    componentFactory_.Register< FightComponent >( ActorComponent::GetIdFromName( "FightComponent" ) );
    componentFactory_.Register< OrderComponent >( ActorComponent::GetIdFromName( "OrderComponent" ) );
    componentFactory_.Register< ReactionComponent >( ActorComponent::GetIdFromName( "ReactionComponent" ) );
    componentFactory_.Register< AiComponent >( ActorComponent::GetIdFromName( "AiComponent" ) );
}

ActorPtr    ActorFactory::CreateActor( const std::string& actorResource )
{
    Properties::ptr resource = Properties::ReadXml( actorResource );
    if( !resource )
    {
        return ActorPtr();
    }

    ActorPtr actor = boost::make_shared<Actor>( GetNextId() );

    if( !actor->Init( resource ) )
    {
        return ActorPtr();
    }   

    BOOST_FOREACH(  boost::property_tree::ptree::value_type& v, 
                    resource->get_child( "Actor" ))
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

    return actor;
}

ActorComponentPtr ActorFactory::CreateComponent( boost::property_tree::ptree& data )
{
    std::string name( data.data() );

    ActorComponentPtr   component;

#if 0
    auto it = ActorComponentCreator.find( name );

    if( it != ActorComponentCreator.end() )
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

    return component;
}


