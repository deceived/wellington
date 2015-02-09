#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP

struct Entry
{
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
