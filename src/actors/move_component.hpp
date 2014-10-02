#ifndef MOVE_COMPONENT_HPP
#define MOVE_COMPONENT_HPP


#include "actor_component.hpp"



class MoveComponent : public ActorComponent
{

public:

    typedef std::size_t Id;
    typedef boost::shared_ptr< ActorComponent > ptr;

    static const std::string name_;

	MoveComponent() 
    { 
    }

	virtual ComponentId GetId() const 
    {
        return GetIdFromName( GetName() ); 
    }

	virtual const std::string GetName() const 
    {
        return name_;
    }

	virtual bool Init(Properties::ptr data);
	virtual bool Init(Properties::pointer data);

	virtual void PostInit();

	virtual void Update(int deltaMs) { }
	virtual void OnChanged() { }				

    static ComponentId GetIdFromName( const std::string& name )
	{
        boost::hash<std::string> string_hash;
		return string_hash( name );
	}

private:

};

#endif
