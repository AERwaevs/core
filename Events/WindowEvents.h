#pragma once

#include <Base/Base.h>

#include "../Event.h"

namespace AEON
{
    namespace Graphics
    {
        class Window;   // forward declare
    }

    class WindowEvent : public Event
    {
    public:
        WindowEvent( Graphics::Window* window ) : _window( window ) {};
        
        Observer<Graphics::Window>  window() const { return _window; }
    private:
        Observer<Graphics::Window>  _window;
    };

    class WindowCloseEvent : public WindowEvent
    {
    public:
        WindowCloseEvent( Graphics::Window* window ) : WindowEvent( window ) {};
    };

    class WindowResizeEvent : public WindowEvent
    {
    public:
        WindowResizeEvent( Graphics::Window* window, 
                           uint32_t size_x, uint32_t  size_y ) 
        : WindowEvent( window ), _size_x( size_x ), _size_y( size_y )
        {};

        uint32_t    x() const { return _size_x; }
        uint32_t    y() const { return _size_y; }
    private:
        uint32_t    _size_x;
        uint32_t    _size_y;
    };

    class WindowMinimizeEvent : public WindowEvent
    {
    public:
        WindowMinimizeEvent( Graphics::Window* window ) : WindowEvent( window ) {};
    };
    
    class WindowMaximizeEvent : public WindowEvent
    {
    public:
        WindowMaximizeEvent( Graphics::Window* window ) : WindowEvent( window ) {};
    };
        
    class WindowFocusEvent : public WindowEvent
    {
    public:
        WindowFocusEvent( Graphics::Window* window ) : WindowEvent( window ) {};
    };
            
    class WindowUnfocusEvent : public WindowEvent
    {
    public:
        WindowUnfocusEvent( Graphics::Window* window ) : WindowEvent( window ) {};
    };
            
    class WindowMoveEvent : public WindowEvent
    {
    public:
        WindowMoveEvent( Graphics::Window* window, 
                         uint32_t pos_x, uint32_t pos_y )
        : WindowEvent( window), _pos_x( pos_x ), _pos_y( pos_y ) {};
        
        uint32_t    x() const { return _pos_x; }
        uint32_t    y() const { return _pos_y; }
    private:
        uint32_t    _pos_x;
        uint32_t    _pos_y;
    };
}