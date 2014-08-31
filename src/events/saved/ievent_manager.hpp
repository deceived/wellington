#ifndef IEVENT_MANAGER_HPP
#define IEVENT_MANAGER_HPP

class IEventManager
{

public:

    enum Constants { INFINITE = 0xffffffff };

    IEventManager( const char* name, bool global );
    virtual ~IEventManager();

    virtual bool AddListener( const EventListenerDelegate& eventDelegate, const EventType& type ) = 0;
    virtual bool RemoveListener( const EventListenerDelegate& eventDelegate, const EventType& type ) = 0;

    virtual bool TriggerEvent( const IEventDataPtr& event ) const = 0;

    virtual bool QueueEvent( const IEventDataPtr& event ) = 0;

    virtual bool AbortEvent( const EventType& type, bool allOfType = false ) = 0;

    virtual bool TickUpdate( unsigned long maxMilliseconds = INFINITE ) = 0;

};

#endif
