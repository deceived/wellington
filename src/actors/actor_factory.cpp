#include "actor_factory.hpp"

#include "identity_component.hpp"
#include "move_component.hpp"
#include "representation_component.hpp"
#include "fire_component.hpp"



ActorFactory::ActorFactory()
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );

    componentFactory_.Register< IdentityComponent >( ActorComponent::GetIdFromName( IdentityComponent::name_ ) );
    componentFactory_.Register< MoveComponent >( ActorComponent::GetIdFromName( MoveComponent::name_ ) );
    componentFactory_.Register< RepresentationComponent >( ActorComponent::GetIdFromName( RepresentationComponent::name_ ) );
    componentFactory_.Register< FireComponent >( ActorComponent::GetIdFromName( FireComponent::name_ ) );
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
        logger.Severity( severity_level::debug, component.name() );
        logger.Severity( severity_level::debug, component.attribute( "name" ).value() );
        ActorComponentPtr cp( CreateComponent( component ) );
        if( cp )
        { 
            logger.Severity( severity_level::info, "actor component ptr not null" );
            actor->AddComponent( cp );
            cp->SetOwner( actor );
        }
        else
        {
            logger.Severity( severity_level::info, "actor ptr null (component ptr null)" );
            return ActorPtr();
        } 
    }
 
    actor->PostInit();

    logger.Severity( severity_level::info, "actor ptr not null" );
    return actor;
}


ActorComponentPtr ActorFactory::CreateComponent( pugi::xml_node  component )
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    logger.Severity( severity_level::debug, component.attribute( "name" ).value() );

    ActorComponentPtr   cp( componentFactory_.Create( ActorComponent::GetIdFromName( component.attribute("name").value() ) ) );
    if( cp )
    {
    	logger.Severity( severity_level::info, "actor component ptr not null" );
        if( !cp->Init( component ) )
        {
    	    logger.Severity( severity_level::info, "actor component ptr null(0)" );
            return ActorComponentPtr();
        }
    }
    else
    {
    	logger.Severity( severity_level::info, "actor component ptr null(1)" );
        return ActorComponentPtr();
    }
    logger.Severity( severity_level::info, "actor component ptr not null" );
    return cp;
}

