#ifndef STDSCR_MAP_CONTROLLER_HPP
#define STDSCR_MAP_CONTROLLER_HPP

#include <boost/smart_ptr.hpp>
#include <boost/program_options.hpp>

#include "stdscr_model.hpp"
#include "stdscr_view.hpp"

class StdScrMapController
{

public:

	StdScrMapController( boost::program_options::variables_map& vm )
		: 	model_( boost::make_shared< StdScrModel >() ),
			view_( boost::make_shared< StdScrView >() ),
			options_( vm )
	{
	}

	void Init();

	void LoadMap();
	void LoadKey();

	void DisplayMap();
	void DisplayKey();
	void DisplayCommand();

	void ClearCmd();

	std::string ReadCmd();

	void UpdateMap();

private:

	boost::shared_ptr< StdScrModel > model_;
	boost::shared_ptr< StdScrView >  view_;

	boost::program_options::variables_map& options_;

};

#endif

