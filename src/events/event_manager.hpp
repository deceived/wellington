#ifndef EVENT_MANAGER_HPP
#define EVENT_MANAGER_HPP

#include <list>
#include <map>

#include "ievent_maager.hpp"

class EventManager : public IEventManager
{

    static const int EventManagerQueueCount = 2;

    typedef std::list< EventListenerDelegate > EventListenerList;
    typedef std::map< EventType, EventListenerList > EventListenerMap;
    typedef std::list< IEventDataPtr > EventQueue;


public:

    enum Constants { INFINITE = 0xffffffff };

    EventManager( const char* name, bool global );
    virtual ~EventManager() {}

    virtual bool AddListener( const EventListenerDelegate& eventDelegate, const EventType& type );
    virtual bool RemoveListener( const EventListenerDelegate& eventDelegate, const EventType& type );

    virtual bool TriggerEvent( const IEventDataPtr& event ) const;

    virtual bool QueueEvent( const IEventDataPtr& event );

    virtual bool AbortEvent( const EventType& type, bool allOfType = false );

    virtual bool TickUpdate( unsigned long maxMilliseconds = INFINITE );

private:

    EventListenerMap eventListeners_;
    EventQueue queues_[ EventManagerQueueCount ];
    int activeQueue_;

};

#endif
