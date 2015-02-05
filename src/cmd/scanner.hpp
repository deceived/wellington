#ifndef SCANNER_HPP
#define SCANNER_HPP

#include <istream>

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

	void NextToken()
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
					break;

				case DIGIT:
					break;

				case '.':
					break;
			}
		}		
	}

private:

	ScannerStream	ifstream_;

};

#endif

