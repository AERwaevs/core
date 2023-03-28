#pragma once

#include <Base/Base.h>

namespace AEON
{
    class Event : public Object< Event >
    {
    public:
        virtual ~Event() = default;

        bool handled() const { return _handled; }

        template< typename E, typename T, typename F > 
        bool Dispatch( const T& target, const F& function )
        {
            return _handled |= typeid( *this ) == typeid( E )
                            ? (target->*function)( static_cast<E&>(*this) )
                            : false;
        }

    private:
        bool      _handled = false;
    };

    using Events = List<ref_ptr<Event>>;

}