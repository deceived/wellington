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
    bool ok = false;
    ok = componentFactory_.Register< IdentityComponent >( ActorComponent::GetIdFromName( "IdentityComponent" ) );
    if( ok ) { std::cout << "id component registered ok" << std::endl; }
    ok = componentFactory_.Register< SpriteComponent >( ActorComponent::GetIdFromName( "SpriteComponent" ) );
    if( ok ) { std::cout << "sprite component registered ok" << std::endl; }
    ok = componentFactory_.Register< MoveComponent >( ActorComponent::GetIdFromName( "MoveComponent" ) );
    if( ok ) { std::cout << "move component registered ok" << std::endl; }
    ok = componentFactory_.Register< FightComponent >( ActorComponent::GetIdFromName( "FightComponent" ) );
    if( ok ) { std::cout << "fight component registered ok" << std::endl; }
    ok = componentFactory_.Register< OrderComponent >( ActorComponent::GetIdFromName( "OrderComponent" ) );
    if( ok ) { std::cout << "order component registered ok" << std::endl; }
    ok = componentFactory_.Register< ReactionComponent >( ActorComponent::GetIdFromName( "ReactionComponent" ) );
    if( ok ) { std::cout << "reaction component registered ok" << std::endl; }
    ok = componentFactory_.Register< AiComponent >( ActorComponent::GetIdFromName( "AiComponent" ) );
    if( ok ) { std::cout << "ai component registered ok" << std::endl; }
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
        std::cout << " v.first : " << v.first << std::endl;
        Properties::ptr p = boost::make_shared< Properties::property_tree >( v.second );

        ActorComponentPtr component( CreateComponent( v.first, p ) );
        if ( component )
        {
            std::cout << "component is initialised" << std::endl;
        } 
        else
        {
            std::cout << "component is null" << std::endl;
        }
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
    write_xml( std::cout, *data );
    ActorComponentPtr   component( componentFactory_.Create( ActorComponent::GetIdFromName( name ) ) );
    if( component )
    {
        std::cout << "component ptr initialised" << std::endl;
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


