#include "dictionary.hpp"



Dictionary::Dictionary()
{
	dictionary_[ "attack" ] = new Entry( std::string( "attack" ), Verb, Attack, Strong );
	dictionary_[ "move"   ] = new Entry( std::string( "move" ), Verb, Neutral, Neutral );
	dictionary_[ "defend" ] = new Entry( std::string( "defend" ), Verb, Defend, Strong );
	dictionary_[ "support"] = new Entry( std::string( "support" ), Verb, Attack, Neutral );
	dictionary_[ "advance"] = new Entry( std::string( "advance" ), Verb, Attack, Neutral );
	dictionary_[ "occupy" ] = new Entry( std::string( "occupy" ), Verb, Neutral, Weak );
	dictionary_[ "hold"   ] = new Entry( std::string( "hold" ), Verb, Defend, Neutral );
}

Entry Dictionary::Get( std::string )
{
}

