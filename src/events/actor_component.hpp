#ifndef ACTOR_COMPONENT_HPP
#define ACTOR_COMPONENT_HPP

#include <boost/smart_ptr.hpp>

#include "actor.hpp"



class ActorComponent
{

public:

    typedef boost::shared_ptr< ActorComponent > ptr;

	virtual ~ActorComponent() 
    { 
        owner_.reset(); 
    }

#if 0
	virtual bool Init(XmlElement* data) = 0;
	virtual void PostInit() { }
	virtual void Update(int deltaMs) { }
	virtual void OnChanged() { }				

    virtual TiXmlElement* GenerateXml() = 0;

	virtual Component::Id GetId() const 
    { 
        return GetIdFromName( GetName() ); 
    }
	virtual const std::string GetName() const = 0;

    static Component::Id GetIdFromName( const std::string& component )
	{
		void* rawId = HashedString::hash_name( component );
		return std::reinterpret_cast<Component::Id>( rawId );
	}
#endif

private:

	void SetOwner(Actor::ptr owner) 
    { 
        owner_ = owner; 
    }

    Actor::ptr  owner_;

};

#endif
