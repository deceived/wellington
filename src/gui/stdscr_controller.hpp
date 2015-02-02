#ifndef STDSCR_MAP_CONTROLLER_HPP
#define STDSCR_MAP_CONTROLLER_HPP

#include <vector>

#include <boost/smart_ptr.hpp>
#include <boost/program_options.hpp>
#include <boost/algorithm/string.hpp>

#include "logger.hpp"
#include "xml_file_resource.hpp"
#include "xml_doc_resource.hpp"
#include "properties.hpp"
#include "resource_cache.hpp"

#include "actor_factory.hpp"
#include "move_component.hpp"
#include "representation_component.hpp"

#include "stdscr_model.hpp"
#include "stdscr_view.hpp"

#include "driver.hpp"

extern Log logger;

class StdScrMapController
{

public:

	typedef boost::shared_ptr< std::string > line_ptr;
	typedef std::vector< std::string > split_vector_type;

	StdScrMapController( boost::program_options::variables_map& vm );

	void Init();
	void Reset();
	void ResetDisplay();
	void Terminate();

	void Load();
	void Display();

	void LoadMap();
	void LoadKey();

	void DisplayMap();
	void DisplayKey();
	void DisplayCommand();
	void DisplayUnits();

	void ClearCmd();

	void Load( line_ptr command );
	void LoadResources();
	line_ptr ReadCmd();

	void EnterOrders();

	void UpdateMap();

	void Run();

private:

	ActorFactory	actorFactory_;

	std::vector< ActorPtr > actors_;

	StdScrModel::model_ptr model_;
	StdScrView::view_ptr  view_;

	boost::program_options::variables_map& options_;

	ResourceCache	cache_;

	std::string	mapFileName_;
	std::string mapKeyFileName_;
	float scale_;

};

#endif

