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
        return ActorPtr();
    }

    ActorPtr actor = boost::make_shared<Actor>( GetNextId() );

    if( !actor->Init( resource ) )
    {
        return ActorPtr();
    }   

    pugi::xml_node components = resource->child( "Actor" ).child( "Components" );

    for( pugi::xml_node component: components.children( "Component" ) )
    {
        ActorComponentPtr cp( CreateComponent( component ) );
        if( cp )
        {
            actor->AddComponent( cp );
            cp->SetOwner( actor );
        }
        else
        {
            return ActorPtr();
        } 
    }
 
    actor->PostInit();

    return actor;
}


ActorComponentPtr ActorFactory::CreateComponent( pugi::xml_node  component )
{

    ActorComponentPtr   cp( componentFactory_.Create( ActorComponent::GetIdFromName( component.attribute("name").value() ) ) );
    if( cp )
    {
        if( !cp->Init( component ) )
        {
            return ActorComponentPtr();
        }
    }
    else
    {
        return ActorComponentPtr();
    }
    return cp;
}

