#include <iostream>

#include "actor_factory.hpp"

int main( int argc, char** argv )
{

    ActorFactory    actorFactory;

    Actor::ptr wellington = actorFactory.CreateActor( "wellington" );
    Actor::ptr line20thFoot = actorFactory.CreateActor( "20thFoot" );
    Actor::ptr heavyCavalryScotsGreys = actorFactory.CreateActor( "scotgreys" );
    Actor::ptr rifles92ndRifles = actorFactory.CreateActor( "92ndRifles" );
    

    return 0;
}
