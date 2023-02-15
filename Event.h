#pragma once

namespace AEON
{
    class AEON_DLL Event : public Inherit< Object, Event >
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