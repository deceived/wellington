#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

#include <string>
#include <map>



struct Entry
{
	static const unsigned int Verb = 0x1;
	static const unsigned int Noun = 0x2;

	static const unsigned int Neutral = 0x1;
	static const unsigned int Defend = 0x2;
	static const unsigned int Attack = 0x4;

	static const unsigned int Strong = 5;
	static const unsigned int Neutral = 3;
	static const unsigned int Weak = 1;

	Entry( 	const std::string& value, 
			unsigned int speech,
			unsigned int action,
			unsigned int strength )
		: 	value_( value ),
			speech_( speech ),
			action_( action ),
			strength_( strength )
	{}

	unsigned int speech_;
	unsigned int action_;
	unsigned int strength_;

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
