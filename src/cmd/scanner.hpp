#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <istream>

#include "scan.h"

class	ScannerStream
{

public:

	ScannerStream( const std::string& filename )
		filename_( filename )
	{
		input_.open( filename_, std::ifstream::in );
	}

	~ScannerStream()
	{
		input_.close();
	}

	int Get()
	{
		if( !input_.eof() )
		{
			return input_.get();
		}
	}

	void Unput()
	{
		if( !input_.eof() )
		{
			input_.unget();
		}
	}


private:

	std::string filename_;
	std::ifstream input_;
	
};

class Scanner
{

public:

	const static int ALPHA = 'a';
	const static int DIGIT = '0';

	Scanner( const std::string& filename )
		: ifstream( filename )
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

private:

	ScannerStream	ifstream_;
	std::string		token_;

};

#endif

