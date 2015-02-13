#include "dictionary.hpp"



Dictionary::Dictionary()
{
	dictionary_[ "attack" ] = new Entry( std::string( "attack" ), Verb, Attack, Strong );
	dictionary_[ "move"   ] = new Entry( std::string( "move" ), Verb, Neutral, Medium );
	dictionary_[ "defend" ] = new Entry( std::string( "defend" ), Verb, Defend, Strong );
	dictionary_[ "support"] = new Entry( std::string( "support" ), Verb, Attack, Medium );
	dictionary_[ "advance"] = new Entry( std::string( "advance" ), Verb, Attack, Medium );
	dictionary_[ "occupy" ] = new Entry( std::string( "occupy" ), Verb, Neutral, Weak );
	dictionary_[ "hold"   ] = new Entry( std::string( "hold" ), Verb, Defend, Medium );
}

Entry* Dictionary::Get( const std::string& token )
{
	return dictionary_[ token ];
}

