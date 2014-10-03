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
    return true;
}

void Actor::PostInit(void)
{
    for( ActorComponents::iterator it = components_.begin(); it != components_.end(); ++it )
    {
        it->second->PostInit();
    }
}

void Actor::Destroy(void)
{
    components_.clear();
}

void Actor::Update( int deltaMs )
{
    for( ActorComponents::iterator it = components_.begin(); it != components_.end(); ++it )
    {
        it->second->Update( deltaMs );
    }
}

void Actor::AddComponent( ActorComponentPtr component )
{
    std::pair<ActorComponents::iterator, bool> success = components_.insert( std::make_pair( component->GetId(), component ) );
}

