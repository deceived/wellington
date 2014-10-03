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
    Properties::pointer resource = Properties::ReadXmlDoc( actorResource );
    if( !resource )
    {
        std::cout << "resource read" << std::endl;
        return ActorPtr();
    }

    ActorPtr actor = boost::make_shared<Actor>( GetNextId() );

    if( !actor->Init( resource ) )
    {
        return ActorPtr();
    }   

    BOOST_FOREACH(  pugi::xml_node& node,
                    (*resource).children( "Actor" ) )
    {
        std::cout << "node.name():" << node.name() << std::endl;
        std::cout << "node.child():" << node.child("Actor").name() << std::endl;
    }

    for(    pugi::xml_node node = resource->child( "Actor" );
            node;
            node = node.next_sibling( "Actor" ) )
    {
        std::cout << "node.name()" << node.name() << std::endl;
        ActorComponentPtr component( CreateComponent( node ) );
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


ActorComponentPtr ActorFactory::CreateComponent( pugi::xml_node  data )
{
    ActorComponentPtr   component( componentFactory_.Create( ActorComponent::GetIdFromName( data.name() ) ) );
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

