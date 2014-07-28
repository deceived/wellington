#ifndef EVENTS_HPP
#define EVENTS_HPP

#include "event_data.hpp"

typedef unsigned long EventType;

class EventDestroyActor : public EventDataBase
{

public:

    static const EventType eventType_;

    explicit EventDestroyActor( ActorId id )
        : id_( id )
    {}

    virtual const EventType& GetEventType() const
    {
        return eventType_;
    }

    virtual const char* GetName() const
    {
        return "EventDestroyActor";
    }

    ActorId GetId() const
    {
        return id_;
    }

private:

    ActorId id_;

};

#endif

