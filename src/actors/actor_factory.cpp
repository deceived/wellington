#include "actor_factory.hpp"

#include "identity_component.hpp"
#include "move_component.hpp"



ActorFactory::ActorFactory()
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    componentFactory_.Register< IdentityComponent >( ActorComponent::GetIdFromName( IdentityComponent::name_ ) );
    componentFactory_.Register< MoveComponent >( ActorComponent::GetIdFromName( MoveComponent::name_ ) );
}



ActorPtr    ActorFactory::CreateActor( const std::string& actorResource )
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
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
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
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

