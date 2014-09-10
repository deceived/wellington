#ifndef MOVE_COMPONENT_HPP
#define MOVE_COMPONENT_HPP


#include "actor_component.hpp"



class MoveComponent : public ActorComponent
{

public:

    typedef std::size_t Id;
    typedef boost::shared_ptr< ActorComponent > ptr;

	MoveComponent() 
    { 
    }

	virtual ~MoveComponent() 
    { 
        //owner_.reset(); 
    }

	virtual void PostInit() { }
	virtual void Update( int deltaMs) { }
	virtual ActorComponent::Id GetId() const 
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
