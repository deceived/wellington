#ifndef MAP_MODEL_HPP
#define MAP_MODEL_HPP


class MapModel
{

public:

	MapModel(  	boost::shared_ptr< Map > map,
				boost::shared_ptr< MapKey > mapKey,
				boost::shared_ptr< Command > command )
		: map_( map ),
		  mapKey_( mapKey ),
		  command_( command )
	{}

	boost::shared_ptr< Map >	GetMap()
	{
		return map_;
	}

	boost::shared_ptr< MapKey >	GetMapKey()
	{
		return map_;
	}

	boost::shared_ptr< Command >	GetCommand()
	{
		return map_;
	}
	
private:

	boost::shared_ptr< Map >		map_;
	boost::shared_ptr< MapKey >		mapKey_;
	boost::shared_ptr< Command >	command_;
};

#endif

