#include <iostream>

#include "actor_factory.hpp"

int main( int argc, char** argv )
{

    ActorFactory    actorFactory;

    ActorPtr wellington = actorFactory.CreateActor( "Wellington.xml" );
    ActorPtr line20thFoot = actorFactory.CreateActor( "20thFoot.xml" );
    ActorPtr heavyCavalryScotsGreys = actorFactory.CreateActor( "ScotsGreys.xml" );
    ActorPtr rifles92ndRifles = actorFactory.CreateActor( "95thRifles.xml" );
    

    return 0;
}
