#pragma once

#include <Input/MouseCodes.h>
#include <Core/Events/WindowEvents.h>


namespace AEON
{
    class AEON_DLL MouseEvent : public WindowEvent
    {
    public:
        MouseEvent( Window* window, 
                    const int32_t& x, const int32_t& y ) 
        : WindowEvent( window ), m_pos_x( x ), m_pos_y( y )
        {};

        int32_t x() const { return m_pos_x;  }
        int32_t y() const { return m_pos_y;  }
    private:
        int32_t m_pos_x;
        int32_t m_pos_y;
    };

    class AEON_DLL MouseMoveEvent : public MouseEvent
    {
    public:
        MouseMoveEvent( Window* window, 
                        const int32_t& x, const int32_t& y ) 
        : MouseEvent( window, x, y )
        {};
    };

    class AEON_DLL MouseScrollEvent : public MouseEvent
    {
    public:
        MouseScrollEvent( Window* window, 
                          const int32_t& x, const int32_t& y,
                          const int32_t& delta_z ) 
        : MouseEvent( window, x, y ), m_delta_z( delta_z )
        {};
        int32_t z() const { return m_delta_z; }
    private:
        int32_t m_delta_z;
    };

    class AEON_DLL MouseButtonEvent : public MouseEvent
    {
    public:
        MouseButtonEvent( Window* window, 
                          const int32_t& x, const int32_t& y, 
                          Mouse::Code button )
        : MouseEvent( window, x, y ), m_button( button ) 
        {};
        
        Mouse::Code button() const { return m_button; }
    private:
        Mouse::Code m_button;
    };
    
    class AEON_DLL MouseDownEvent : public MouseButtonEvent
    {
    public:
        MouseDownEvent( Window* window, 
                           const int32_t& x, const int32_t& y, 
                           Mouse::Code button ) 
        : MouseButtonEvent( window, x, y, button )
        {};
    };
        
    class AEON_DLL MouseUpEvent : public MouseButtonEvent
    {
    public:
        MouseUpEvent( Window* window, 
                            const int32_t& x, const int32_t& y, 
                            Mouse::Code button ) 
        : MouseButtonEvent( window, x, y, button )
        {};
    };

    class AEON_DLL MouseDoubleEvent : public MouseButtonEvent
    {
    public:
        MouseDoubleEvent( Window* window, 
                                 const int32_t& x, const int32_t& y, 
                                 Mouse::Code button )
        : MouseButtonEvent( window, x, y, button )
        {};
    };
}