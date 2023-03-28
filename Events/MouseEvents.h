#pragma once

#include <Input/MouseCodes.h>
#include <Core/Events/WindowEvents.h>


namespace AEON
{
    class MouseEvent : public WindowEvent
    {
    public:
        MouseEvent( Graphics::Window* window, 
                    const int32_t& x, const int32_t& y ) 
        : WindowEvent( window ), _pos_x( x ), _pos_y( y )
        {};

        int32_t x() const { return _pos_x;  }
        int32_t y() const { return _pos_y;  }
    private:
        int32_t _pos_x;
        int32_t _pos_y;
    };

    class MouseMoveEvent : public MouseEvent
    {
    public:
        MouseMoveEvent( Graphics::Window* window, 
                        const int32_t& x, const int32_t& y ) 
        : MouseEvent( window, x, y )
        {};
    };

    class MouseScrollEvent : public MouseEvent
    {
    public:
        MouseScrollEvent( Graphics::Window* window, 
                          const int32_t& x, const int32_t& y,
                          const int32_t& delta_z ) 
        : MouseEvent( window, x, y ), _delta_z( delta_z )
        {};
        int32_t z() const { return _delta_z; }
    private:
        int32_t _delta_z;
    };

    class MouseButtonEvent : public MouseEvent
    {
    public:
        MouseButtonEvent( Graphics::Window* window, 
                          const int32_t& x, const int32_t& y, 
                          Mouse::Code button )
        : MouseEvent( window, x, y ), _button( button ) 
        {};
        
        Mouse::Code button() const { return _button; }
    private:
        Mouse::Code _button;
    };
    
    class MouseDownEvent : public MouseButtonEvent
    {
    public:
        MouseDownEvent( Graphics::Window* window, 
                           const int32_t& x, const int32_t& y, 
                           Mouse::Code button ) 
        : MouseButtonEvent( window, x, y, button )
        {};
    };
        
    class MouseUpEvent : public MouseButtonEvent
    {
    public:
        MouseUpEvent( Graphics::Window* window, 
                            const int32_t& x, const int32_t& y, 
                            Mouse::Code button ) 
        : MouseButtonEvent( window, x, y, button )
        {};
    };

    class MouseDoubleEvent : public MouseButtonEvent
    {
    public:
        MouseDoubleEvent( Graphics::Window* window, 
                                 const int32_t& x, const int32_t& y, 
                                 Mouse::Code button )
        : MouseButtonEvent( window, x, y, button )
        {};
    };
}