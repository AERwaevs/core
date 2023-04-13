#pragma once

#include "../Base/Base.h"

namespace AEON
{
    struct Event : public Object
    {
        virtual ~Event() = default;

        bool handled() const { return _handled; }

        template< typename E, typename T, typename F > 
        bool Dispatch( const T& target, const F& function )
        {
            if( typeid( *this ) != typeid( E ) ) return false;
            AE_INFO( "Dispatching %s to %s", type_name( static_cast<E&>(*this) ), type_name( function ) );

            _handled |= (target->*function)( static_cast<E&>(*this) );
            AE_WARN_IF( !_handled, "Unhandled %s", type_name( static_cast<E&>(*this) ) );
            return _handled;
        }

    private:
        bool      _handled = false;
    };

    using Events = List<ref_ptr<Event>>;
}