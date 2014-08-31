#ifndef EVENT_HPP
#define EVENT_HPP

/***

   Heavily borrowed from Game Coding Complete, 4th Edition. But I figure
   Mike McShaffrey owes me, as he borrowed my review of the original,
   for the 2nd and 3rd Editions. 

   Thanks for a great series.

   -- spotland (Rochdale AFC's ground)

***/

#include <time.h>

class   IEvent
{

public:
    
    virtual const EventType& GetEventType() = 0;
    virtual clock_t GetTimeStamp() = 0;
    virtual const char* GetName() = 0;
 
};

class EventBase : public IEvent
{

    const clock_t timeStamp_;

public:

    explicit EventBase( const clock_t timeStamp = 0 )
        : timeStamp_( timeStamp )
    {}

    virtual const EventType& GetEventType() const = 0;

    clock_t GetTimeStamp() const
    {
        return timeStamp_;
    }
};

#endif

