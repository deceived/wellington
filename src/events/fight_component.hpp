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

	virtual ~FightComponent() 
    { 
        //owner_.reset(); 
    }

	virtual void PostInit() { }
	virtual void Update( int deltaMs) { }
	virtual ActorComponentId GetId() const 
    {
        return 0; 
        //return GetIdFromName( GetName() ); 
    }
	virtual const std::string GetName() const {};

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

    static Id GetIdFromName( const std::string& name )
	{
        boost::hash<std::string> string_hash;

		return string_hash( name );
	}

private:

#if 0
	void SetOwner(Actor::ptr owner) 
    { 
        owner_ = owner; 
    }
#endif
    //Actor::ptr  owner_;

};

#endif
