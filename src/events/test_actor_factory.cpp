#include <iostream>

#include "actor_factory.hpp"

int main( int argc, char** argv )
{

    ActorFactory    actorFactory;

    Actor::ptr wellington = actorFactory.CreateActor( "Wellington.xml" );
    Actor::ptr line20thFoot = actorFactory.CreateActor( "20thFoot.xml" );
    Actor::ptr heavyCavalryScotsGreys = actorFactory.CreateActor( "ScotsGreys.xml" );
    Actor::ptr rifles92ndRifles = actorFactory.CreateActor( "95thRifles.xml" );
    

    return 0;
}
