#pragma once

#include <Base/Base.h>

namespace AEON
{
    class Event : public Object< Event >
    {
    public:
        virtual ~Event() = default;

        template< typename E, typename F > 
        bool Dispatch( const F& function )
        {
            return m_handled |= typeid( *this ) == typeid( E )
                              ? function( static_cast<E&>(*this) )
                              : false;
        };
    private:
        bool      m_handled = false;
    };

    using Events = List<Shared<Event>>;
}