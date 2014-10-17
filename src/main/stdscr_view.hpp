#ifndef STDSCR_VIEW_HPP
#define STDSCR_VIEW_HPP

#include <string>

#include <boost/smart_ptr.hpp>

#include "map_view.hpp"
#include "key_view.hpp"
#include "cmd_view.hpp"

class StdScrView
{

public:

	typedef boost::shared_ptr< MapView > map_view;
	typedef boost::shared_ptr< KeyView > key_view;
	typedef boost::shared_ptr< CmdView > cmd_view;

	StdScrView();
	~StdScrView();

	void Init();

	void DisplayLine( unsigned int row, unsigned int column, std::string& line );
	void ClearLine( unsigned int row, unsigned int column, int length );

	map_view GetMapView()
	{
		return mapView_;
	}

	key_view GetKeyView()
	{
		return keyView_;
	}

	cmd_view GetCmdView()
	{
		return cmdView_;
	}

private:

	boost::shared_ptr< MapView >	mapView_;
	boost::shared_ptr< KeyView >	keyView_;
	boost::shared_ptr< CmdView >	cmdView_;

	int rows_;
	int columns_;
};


#endif

