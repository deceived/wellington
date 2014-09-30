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
    componentFactory_.Register< IdentityComponent >( ActorComponent::GetIdFromName( IdentityComponent::name_ ) );
    componentFactory_.Register< SpriteComponent >( ActorComponent::GetIdFromName( SpriteComponent::name_ ) );
    componentFactory_.Register< MoveComponent >( ActorComponent::GetIdFromName( MoveComponent::name_ ) );
    componentFactory_.Register< FightComponent >( ActorComponent::GetIdFromName( FightComponent::name_ ) );
    componentFactory_.Register< OrderComponent >( ActorComponent::GetIdFromName( OrderComponent::name_ ) );
    componentFactory_.Register< ReactionComponent >( ActorComponent::GetIdFromName( ReactionComponent::name_ ) );
    componentFactory_.Register< AiComponent >( ActorComponent::GetIdFromName( AiComponent::name_ ) );
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
                    (*resource).get_child( "Actor" ))
    {
        Properties::ptr p = boost::make_shared< Properties::property_tree >( v.second );

        ActorComponentPtr component( CreateComponent( v.first, p ) );
#if 0
        if( component )
        {
            actor->AddComponent( component );
            component->SetOwner( actor );
        }
        else
        {
            return ActorPtr();
        } 
#endif
    }

    actor->PostInit();

    return actor;
}

ActorComponentPtr ActorFactory::CreateComponent( const std::string& name, Properties::ptr  data )
{
    ActorComponentPtr   component( componentFactory_.Create( ActorComponent::GetIdFromName( name ) ) );
    if( component )
    {
        if( !component->Init( data ) )
        {
            return ActorComponentPtr();
        }
    }
    else
    {
        return ActorComponentPtr();
    }
    return component;
}

