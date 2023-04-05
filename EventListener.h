#pragma once

#include "Event.h"
#include "../Base/Base.h"

namespace AEON
{
    
struct IEventListener
{
    template< typename T >
    requires std::derived_from< T, Event > || std::common_reference_with< T, Event >
    inline  void SendEvent( T* event ) { _events.emplace_back( event ); };
    virtual bool PollEvents( Events& unhandled )
    {
        if( _events.size() > 0 )
        {
            _events.remove_if( []( const auto& e ){ return e->handled(); } );
            unhandled.splice( unhandled.end(), _events );
            _events.clear();
            return true;
        }
        else return false;
    };
protected:
    template< typename T >
    requires std::derived_from< T, Event > || std::common_reference_with< T, Event >
    bool OnEvent( T& event ) 
    {
        return false;
    }

protected:
    Events _events;
};

} // namespace AEON