#pragma once

namespace AEON
{
    class AEON_DLL Event : public Object
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