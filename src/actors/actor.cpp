#include "actor.hpp"
#include "actor_component.hpp"

Actor::Actor(ActorId id)
{
    actorId_ = id;
}

Actor::~Actor()
{
}

bool Actor::Init( Properties::pointer data )
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    logger.Severity( severity_level::debug, data->child( "Actor" ).attribute( "type" ) );
    logger.Severity( severity_level::debug, data->child( "Actor" ).attribute( "resource" ) );
    return true;
}

void Actor::PostInit(void)
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    for( ActorComponents::iterator it = components_.begin(); it != components_.end(); ++it )
    {
        it->second->PostInit();
    }
}

void Actor::Destroy(void)
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    components_.clear();
}

void Actor::Update( int deltaMs )
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    for( ActorComponents::iterator it = components_.begin(); it != components_.end(); ++it )
    {
        it->second->Update( deltaMs );
    }
}

void Actor::AddComponent( ActorComponentPtr component )
{
    logger.Severity( severity_level::info, __PRETTY_FUNCTION__ );
    std::pair<ActorComponents::iterator, bool> success = components_.insert( std::make_pair( component->GetId(), component ) );
}

