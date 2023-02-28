#pragma once

#include <Base/Base.h>

namespace AEON
{
    class Event : public Object< Event >
    {
    public:
        virtual ~Event() = default;

        template< typename E, typename T, typename F > 
        bool Dispatch( const T& target, const F& function )
        {
            return m_handled |= typeid( *this ) == typeid( E )
                              ? (target->*function)( static_cast<E&>(*this) )
                              : false;
        };
    private:
        bool      m_handled = false;
    };

    using Events = List<Shared<Event>>;
}