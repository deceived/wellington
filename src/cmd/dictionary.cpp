#include "dictionary.hpp"



Dictionary::Dictionary()
{
	dictionary_[ "attack" ] = *new Entry;
	dictionary_[ "move"   ] = *new Entry;
	dictionary_[ "defend" ] = *new Entry;
	dictionary_[ "support"] = *new Entry;
	dictionary_[ "advance"] = *new Entry;
	dictionary_[ "occupy" ] = *new Entry;
	dictionary_[ "hold"   ] = *new Entry;
}

Entry Dictionary::Get( std::string )
{
}

