#pragma once

#include <Base/Base.h>
#include <Base/Event.h>

#include "../Input/MouseCodes.h"

namespace aer
{

namespace gfx
{
    class Window;   // forward declare
}

struct MouseEvent : public Event
{
    MouseEvent( Window* window, int32_t x, int32_t y ) 
    : _window( window ), _x( x ), _y( y ) {};

    spy_ptr<Window> window() const { return _window; }
    int32_t                   x()      const { return _x;  }
    int32_t                   y()      const { return _y;  }
private:
    spy_ptr<Window>  _window;
    int32_t                    _x;
    int32_t                    _y;
};

struct MouseMoveEvent : public MouseEvent
{
    MouseMoveEvent( auto* window, auto x, auto y ) 
    : MouseEvent( window, x, y ) {};
};

struct MouseScrollEvent : public MouseEvent
{
    MouseScrollEvent( auto* window, auto x, auto y, int32_t z ) 
    : MouseEvent( window, x, y ), _z( z ) {};

    int32_t z() const { return _z; }
private:
    int32_t _z;
};

struct MouseButtonEvent : public MouseEvent
{
    MouseButtonEvent( auto* window, auto x, auto y, Mouse::Code button )
    : MouseEvent( window, x, y ), _button( button ) {};
    
    Mouse::Code button() const { return _button; }
private:
    Mouse::Code _button;
};

struct MouseDownEvent : public MouseButtonEvent
{
    MouseDownEvent( auto* window, auto x, auto y, auto button ) 
    : MouseButtonEvent( window, x, y, button ) {};
};
    
struct MouseUpEvent : public MouseButtonEvent
{
    MouseUpEvent( auto* window, auto x, auto y, auto button ) 
    : MouseButtonEvent( window, x, y, button ) {};
};

struct MouseDoubleEvent : public MouseButtonEvent
{
    MouseDoubleEvent( auto* window, auto x, auto y, auto button )
    : MouseButtonEvent( window, x, y, button ) {};
};

} // namespace aer