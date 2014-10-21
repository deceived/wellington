#ifndef STDSCR_MAP_CONTROLLER_HPP
#define STDSCR_MAP_CONTROLLER_HPP

#include <vector>

#include <boost/smart_ptr.hpp>
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>

#include "xml_file_resource.hpp"
#include "properties.hpp"
#include "resource_cache.hpp"

#include "stdscr_model.hpp"
#include "stdscr_view.hpp"

class StdScrMapController
{

public:

	typedef boost::shared_ptr< std::string > line_ptr;
	typedef std::vector< std::string > split_vector_type;

	StdScrMapController( boost::program_options::variables_map& vm )
		: 	model_( boost::make_shared< StdScrModel >() ),
			view_( boost::make_shared< StdScrView >() ),
			options_( vm )
	{
	}

	void Init();
	void Reset();
	void Terminate();

	void LoadMap();
	void LoadKey();

	void DisplayMap();
	void DisplayKey();
	void DisplayCommand();

	void ClearCmd();

	void Load( line_ptr command );
	void InitialiseDisplay();
	line_ptr ReadCmd();

	void UpdateMap();

	void Run();

private:

	boost::shared_ptr< StdScrModel > model_;
	boost::shared_ptr< StdScrView >  view_;

	boost::program_options::variables_map& options_;

	ResourceCache	cache_;

};

#endif

