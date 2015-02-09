#include "dictionary.hpp"



Dictionary::Dictionary()
{
	dictionary_[ "attack" ] = null;
	dictionary_[ "move"   ] = null;
	dictionary_[ "defend" ] = null;
	dictionary_[ "support"] = null;
	dictionary_[ "advance"] = null;
	dictionary_[ "occupy" ] = null;
	dictionary_[ "hold"   ] = null;
}

Entry Dictionary::Get( std::string )
{
}

