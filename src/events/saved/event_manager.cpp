#include "event_manager.hpp"

EventManager::EventManager( const char* name, bool setAsGlobal )
	: IEventManager( name, setAsGlobal )
{
    activeQueue_ = 0;
}

EventManager::~EventManager()
{ } 

bool EventManager::AddListener( const EventListenerDelegate& eventDelegate, const EventType& type )
{
    EventListenerList& eventListenerList = eventListeners_[ type ];
    for ( auto it = eventListenerList.begin(); it != eventListenerList.end(); ++it )
    {
        if ( eventDelegate == (*it) )
        {
            return false;
        }
    }

    eventListenerList.push_back( eventDelegate );

	return true;
}


bool EventManager::RemoveListener( const EventListenerDelegate& eventDelegate, const EventType& type )
{
	bool success = false;

    auto findIt = eventListeners_.find( type );
    if ( findIt != eventListeners_.end() )
    {
        EventListenerList& listeners = findIt->second;
        for ( auto it = listeners.begin(); it != listeners.end(); ++it )
        {
            if ( eventDelegate == (*it) )
            {
                listeners.erase( it );
                success = true;
                break;  
            }
        }
    }

    return success;
}


bool EventManager::TriggerEvent( const IEventDataPtr& event ) const
{
    bool processed = false;

    auto findIt = eventListeners_.find( event->GetEventType() );
	if ( findIt != eventListeners_.end() )
    {
	    const EventListenerList& eventListenerList = findIt->second;
	    for (EventListenerList::const_iterator it = eventListenerList.begin(); it != eventListenerList.end(); ++it)
	    {
		    EventListenerDelegate listener = (*it);
		    listener( event );
            processed = true;
	    }
    }
	
	return processed;
}


bool EventManager::QueueEvent( const IEventDataPtr& event )
{
    if ( !event )
    {
        return false;
    }

	auto findIt = eventListeners_.find(event->GetEventType());
    if (findIt != eventListeners_.end())
    {
        queues_[ activeQueue_ ].push_back( event );
        return true;
    }
    else
    {
        return false;
    }
}


bool EventManager::ThreadSafeQueueEvent( const IEventDataPtr& event )
{
	realtimeEventQueue_.push( event );
	return true;
}


bool EventManager::AbortEvent( const EventType& inType, bool allOfType )
{
    bool success = false;
	EventListenerMap::iterator findIt = eventListeners_.find( inType );

	if ( findIt != eventListeners_.end() )
    {
        EventQueue& eventQueue = queues_[ activeQueue_ ];
        auto it = eventQueue.begin();
        while ( it != eventQueue.end() )
        {
            auto thisIt = it;
            ++it;

	        if ( (*thisIt)->GetEventType() == inType )
	        {
		        eventQueue.erase( thisIt );
		        success = true;
		        if ( !allOfType )
			        break;
	        }
        }
    }

	return success;
}


bool EventManager::Update(unsigned long maxMillis)
{
	unsigned long currMs = GetTickCount();
	unsigned long maxMs = ((maxMillis == IEventManager::INFINITE) ? (IEventManager::INFINITE) : (currMs + maxMillis));

	IEventDataPtr pRealtimeEvent;
	while ( realtimeEventQueue_.try_pop( realtimeEvent ))
	{
		VQueueEvent( realtimeEvent );

		currMs = GetTickCount();
		if (maxMilliseconds != IEventManager::INFINITE)
		{
			if (currMs >= maxMs)
			{
			}
		}
	}

    int queueToProcess = activeQueue_;
	activeQueue_ = ( activeQueue_ + 1 ) % EventManagerQueueCount;
	queues_[ activeQueue_ ].clear();

	while ( !queues_[ queueToProcess ].empty())
	{
		IEventDataPtr pEvent = queues_[ queueToProcess ].front();
        queues_[ queueToProcess ].pop_front();

		const EventType& eventType = event->GetEventType();

		auto findIt = eventListeners_.find( eventType );
		if ( findIt != eventListeners_.end() )
		{
			const EventListenerList& eventListeners = findIt->second;

			for (auto it = eventListeners.begin(); it != eventListeners.end(); ++it)
			{
                EventListenerDelegate listener = (*it);
				listener(pEvent);
			}
		}

		currMs = GetTickCount();
		if (maxMilliseconds != IEventManager::INFINITE && currMs >= maxMs )
        {
			break;
        }
	}
	
	bool queueFlushed = ( queues_[queueToProcess].empty() );
	if (!queueFlushed)
	{
		while ( !queues_[ queueToProcess ].empty() )
		{
			IEventDataPtr pEvent = queues_[ queueToProcess ].back();
			queues_[ queueToProcess ].pop_back();
			queues_[ activeQueue ].push_front( event );
		}
	}
	
	return queueFlushed;
}

