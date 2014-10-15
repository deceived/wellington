#ifndef CMD_VIEW_HPP
#define CMD_VIEW_HPP

class CmdView
{
	
public:

	void Put( unsigned int row, unsigned int col, std::string line );
	void ClearLine( unsigned int row, unsigned int col, unsigned int length );
	std::string Read( unsigned int row, unsigned int col );

};

#endif

