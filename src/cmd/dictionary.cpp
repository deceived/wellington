#include "dictionary.hpp"



Dictionary::Dictionary()
{
	dictionary_[ "attack" ] = *new Entry( "attack", Entry::Verb, Entry::Attack, Entry::Strong );
	dictionary_[ "move"   ] = *new Entry( "move", Entry::Verb, Entry::Neutral, Entry::Neutral );
	dictionary_[ "defend" ] = *new Entry( "defend", Entry::Verb, Entry::Defend, Entry::Strong );
	dictionary_[ "support"] = *new Entry( "support", Entry::Verb, Entry::Attack, Entry::Neutral );
	dictionary_[ "advance"] = *new Entry( "advance", Entry::Verb, Entry::Attack, Entry::Neutral );
	dictionary_[ "occupy" ] = *new Entry( "occupy", Entry::Verb, Entry::Neutral, Entry::Weak );
	dictionary_[ "hold"   ] = *new Entry( "hold", Entry::Verb, Entry::Defend, Entry::Neutral );
}

Entry Dictionary::Get( std::string )
{
}

