#ifndef ACTOR_COMPONENT_HPP
#define ACTOR_COMPONENT_HPP

#include <boost/smart_ptr.hpp>
#include <boost/functional/hash.hpp>

#include "interfaces.h"
#include "properties.hpp"
#include "pugixml.hpp"



class ActorComponent
{

public:

	virtual ~ActorComponent() 
    { 
        owner_.reset(); 
    }

	virtual ComponentId GetId() const 
    {
        return GetIdFromName( GetName() ); 
    }

	virtual const std::string GetName() const = 0;

	virtual bool Init( pugi::xml_node data ) = 0;

	virtual void PostInit() { }

	virtual void Update(int deltaMs) { }
	virtual void OnChanged() { }				

    static ComponentId GetIdFromName( const std::string& name )
	{
        boost::hash<std::string> string_hash;
		return string_hash( name );
	}

	void SetOwner(ActorPtr owner) 
    { 
        owner_ = owner; 
    }

private:

    ActorPtr  owner_;

};

#endif
