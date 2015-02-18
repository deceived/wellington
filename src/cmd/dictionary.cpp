#include "dictionary.hpp"


namespace order
{

Dictionary::Dictionary()
{
	dictionary_[ "attack" ] = new Entry( std::string( "attack" ), Verb, Attack, Strong );
	dictionary_[ "move"   ] = new Entry( std::string( "move" ), Verb, Neutral, Medium );
	dictionary_[ "defend" ] = new Entry( std::string( "defend" ), Verb, Defend, Strong );
	dictionary_[ "support"] = new Entry( std::string( "support" ), Verb, Attack, Medium );
	dictionary_[ "advance"] = new Entry( std::string( "advance" ), Verb, Attack, Medium );
	dictionary_[ "occupy" ] = new Entry( std::string( "occupy" ), Verb, Neutral, Weak );
	dictionary_[ "hold"   ] = new Entry( std::string( "hold" ), Verb, Defend, Medium );
	dictionary_[ "clear"   ] = new Entry( std::string( "clear" ), Verb, Attack, Medium );

	dictionary_[ "town"   ] = new Entry( std::string( "town" ), Noun, Neutral, Strong );
	dictionary_[ "hill"   ] = new Entry( std::string( "hill" ), Noun, Neutral, Strong );
	dictionary_[ "village"   ] = new Entry( std::string( "village" ), Noun, Neutral, Strong );
	dictionary_[ "wood"   ] = new Entry( std::string( "wood" ), Noun, Neutral, Strong );
	dictionary_[ "bridge"   ] = new Entry( std::string( "bridge" ), Noun, Neutral, Medium );
	dictionary_[ "road"   ] = new Entry( std::string( "road" ), Noun, Neutral, Weak );
	dictionary_[ "farm"   ] = new Entry( std::string( "farm" ), Noun, Neutral, Medium );
	dictionary_[ "field"   ] = new Entry( std::string( "field" ), Noun, Neutral, Medium );
	dictionary_[ "crossroads"   ] = new Entry( std::string( "crossroads" ), Noun, Neutral, Weak );

	dictionary_[ "north"   ] = new Entry( std::string( "north" ), Noun, Neutral, Medium );
	dictionary_[ "south"   ] = new Entry( std::string( "south" ), Noun, Neutral, Medium );
	dictionary_[ "east"   ] = new Entry( std::string( "east" ), Noun, Neutral, Medium );
	dictionary_[ "west"   ] = new Entry( std::string( "west" ), Noun, Neutral, Medium );
	dictionary_[ "n"   ] = new Entry( std::string( "n" ), Noun, Neutral, Medium );
	dictionary_[ "s"   ] = new Entry( std::string( "s" ), Noun, Neutral, Medium );
	dictionary_[ "e"   ] = new Entry( std::string( "e" ), Noun, Neutral, Medium );
	dictionary_[ "w"   ] = new Entry( std::string( "w" ), Noun, Neutral, Medium );
	dictionary_[ "nw"   ] = new Entry( std::string( "nw" ), Noun, Neutral, Medium );
	dictionary_[ "sw"   ] = new Entry( std::string( "sw" ), Noun, Neutral, Medium );
	dictionary_[ "ne"   ] = new Entry( std::string( "ne" ), Noun, Neutral, Medium );
	dictionary_[ "nw"   ] = new Entry( std::string( "nw" ), Noun, Neutral, Medium );
}

Entry* Dictionary::Get( const std::string& token )
{
	std::string key( token );
	boost::to_lower( key );	
	return dictionary_[ key ];
}

}
