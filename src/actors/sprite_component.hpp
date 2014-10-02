#ifndef SPRITE_COMPONENT_HPP
#define SPRITE_COMPONENT_HPP


#include "actor_component.hpp"



class SpriteComponent : public ActorComponent
{

public:

    typedef std::size_t Id;

    static const std::string name_;
 
	SpriteComponent() 
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
