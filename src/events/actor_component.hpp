#ifndef ACTOR_COMPONENT_HPP
#define ACTOR_COMPONENT_HPP

#include <boost/smart_ptr.hpp>
#include <boost/functional/hash.hpp>

class ActorComponent
{

public:

	virtual ~ActorComponent() 
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

    static ActorComponentId GetIdFromName( const std::string& name )
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
