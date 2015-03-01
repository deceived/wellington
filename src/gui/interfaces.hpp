#ifndef INTERFACES_HPP
#define INTERFACES_HPP

#include <string>

class	IKey
{

public:

	virtual void Load( const std::string& fileName ) = 0;
	virtual unsigned int GetRows() = 0;
	virtual unsigned int GetColumns() = 0;
	virtual line_ptr GetRow( unsigned int index ) = 0;
	virtual size_t LineCount() = 0;
	virtual line_ptr NextLine( size_t count ) = 0;

};


class StdScrIModel
{

public:

	typedef boost::shared_ptr< StdScrIModel > imodel_ptr;

	virtual void Init() = 0;
	virtual void Reset() = 0;
	virtual void Terminate() = 0;

	virtual void Load() = 0;
	virtual void Display() = 0;

	virtual void LoadMap() = 0;
	virtual void LoadKey() = 0;

	virtual void DisplayMap() = 0;
	virtual void DisplayKey() = 0;
	virtual void DisplayCommand() = 0;
	virtual void DisplayUnits() = 0;

	virtual void LoadMap( const std::string& fileName ) = 0;
	virtual void LoadKey( const std::string& fileName ) = 0;

};

#endif

