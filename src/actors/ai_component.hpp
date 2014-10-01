#ifndef AI_COMPONENT_HPP
#define AI_COMPONENT_HPP

#include "actor_component.hpp"

class AiComponent : public ActorComponent
{

public:

    typedef std::size_t Id;

    static const std::string name_;

	AiComponent() 
    { 
    }

	virtual ActorComponentId GetId() const 
    {
        return GetIdFromName( GetName() ); 
    }

	virtual const std::string GetName() const 
    {
        return name_;
    }

	virtual bool Init(Properties::ptr data) { return true; };
	virtual void PostInit() { }
	virtual void Update(int deltaMs) { }
	virtual void OnChanged() { }				

    static ActorComponentId GetIdFromName( const std::string& name )
	{
        boost::hash<std::string> string_hash;

		return string_hash( name );
	}

private:

};

#endif
