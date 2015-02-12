#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <string>
#include <map>


enum Speech
{
	Verb = 1,
	Noun
};

enum Action
{
	Attack = 1,
	Neutral,
	Defend
};

enum Strength
{
	Weak = 1,
	Medium,
	Strong
};

struct Entry
{

	Entry( 	const std::string& value, 
			enum Speech speech,
			enum Action action,
			enum Strength strength )
		: 	value_( value ),
			speech_( speech ),
			action_( action ),
			strength_( strength )
	{}

	enum Speech speech_;
	enum Action action_;
	enum Strength strength_;

	const std::string value_;
};



class Dictionary
{

public:

	typedef std::map< std::string, Entry > dictionary_type;

	Dictionary();

	Entry Get( std::string );	

private:

	dictionary_type	dictionary_;

};

#endif
