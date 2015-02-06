#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <istream>

#include "scan.h"


class Scanner
{

public:

	const static int ALPHA = 'a';
	const static int DIGIT = '0';

	Scanner( std::istream& in )
		: ifstream_( in )
	{}

	int Class( int c )
	{
		if( isalpha( c ) )
		{
			return ALPHA;
		}
		if( isdigit( c ) )
		{
			return DIGIT;
		}
		return c;
	}

	symbolclass NextToken()
	{
		int c = ifstream_.Get();

		while( c != EOF )
		{
			switch( Class( c ) )
			{
				case ' ':
				case '\t':
				case '\n':
					break;

				case ALPHA:
					for( int j = 0; isalpha( c ); ++j )
					{
						token_.push_back( c );
						c = ifstream_.Get();	
					}
					token_.push_back( '\0' );
					ifstream_.Unput();
					return WORD;
					break;

				case DIGIT:
					for( int j = 0; isdigit( c ); ++j )
					{
						token_.push_back( c );
						c = ifstream_.Get();	
					}	
					token_.push_back( '\0' );
					ifstream_.Unput();
					return INTEGER;
					break;

				case '.':
					return PERIOD;
					break;
			}
		}
		return EOFSY;
	}

	int Get()
	{
		if( !ifstream_.eof() )
		{
			return ifstream_.get();
		}
	}

	void Unput()
	{
		if( !ifstream_.eof() )
		{
			ifstream_.unget();
		}
	}

private:

	std::istream&	ifstream_;
	std::string		token_;

};

#endif

