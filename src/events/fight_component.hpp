#ifndef FIGHT_COMPONENT_HPP
#define FIGHT_COMPONENT_HPP


#include "actor_component.hpp"


class FightComponent : public ActorComponent
{

public:

    typedef std::size_t Id;

	FightComponent() 
    { 
    }

	virtual ActorComponentId GetId() const 
    {
        return GetIdFromName( GetName() ); 
    }

	virtual const std::string GetName() const {};

	virtual bool Init(Properties::ptr data) {};
	virtual void PostInit() { }
	virtual void Update(int deltaMs) { }
	virtual void OnChanged() { }				

#if 0
    virtual TiXmlElement* GenerateXml() = 0;
#endif

    static ActorComponentId GetIdFromName( const std::string& name )
	{
        boost::hash<std::string> string_hash;

		return string_hash( name );
	}

private:

};

#endif
