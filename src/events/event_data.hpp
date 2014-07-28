#ifndef EVENT_DATA_HPP
#define EVENT_DATA_HPP

/***

   Heavily borrowed from Game Coding Complete, 4th Edition. But I figure
   Mike McShaffrey owes me, as he borrowed my review of the original,
   for the 2nd and 3rd Editions. 

   Thanks for a great series.

   -- spotland (Rochdale AFC's ground)

***/

class   IEventData
{

public:
    
    virtual const EventType& GetEventType() = 0;
    virtual float GetTimeStamp() = 0;
    virtual const char* GetName() = 0;
 
};

class EventDataBase : public IEventData
{

    const float timeStamp_;

public:

    explicit EventDataBase( const float timeStamp = 0.0f )
        : timeStamp_( timeStamp )
    {}

    virtual ~EventDataBase()
    {}

    virtual const EventType& GetEventType() const = 0;
    float GetTimeStamp() const
    {
        return timeStamp_;
    }
};

#endif

