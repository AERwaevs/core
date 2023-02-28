#pragma once

#include <Base/Base.h>

#include <Core/Event.h>

namespace AEON
{
    namespace Graphics
    {
        class Window;   // forward declare
    }

    class AEON_DLL WindowEvent : public Event
    {
    public:
        WindowEvent( Graphics::Window* window ) : m_window( window ) {};
        
        Observer<Graphics::Window>  window() const { return m_window; }
    private:
        Observer<Graphics::Window>  m_window;
    };

    class AEON_DLL WindowCloseEvent : public WindowEvent
    {
    public:
        WindowCloseEvent( Graphics::Window* window ) : WindowEvent( window ) {};
    };

    class AEON_DLL WindowResizeEvent : public WindowEvent
    {
    public:
        WindowResizeEvent( Graphics::Window* window, 
                           uint32_t size_x, uint32_t  size_y ) 
        : WindowEvent( window ), m_size_x( size_x ), m_size_y( size_y )
        {};

        uint32_t    x() const { return m_size_x; }
        uint32_t    y() const { return m_size_y; }
    private:
        uint32_t    m_size_x;
        uint32_t    m_size_y;
    };

    class AEON_DLL WindowMinimizeEvent : public WindowEvent
    {
    public:
        WindowMinimizeEvent( Graphics::Window* window ) : WindowEvent( window ) {};
    };
    
    class AEON_DLL WindowMaximizeEvent : public WindowEvent
    {
    public:
        WindowMaximizeEvent( Graphics::Window* window ) : WindowEvent( window ) {};
    };
        
    class AEON_DLL WindowFocusEvent : public WindowEvent
    {
    public:
        WindowFocusEvent( Graphics::Window* window ) : WindowEvent( window ) {};
    };
            
    class AEON_DLL WindowUnfocusEvent : public WindowEvent
    {
    public:
        WindowUnfocusEvent( Graphics::Window* window ) : WindowEvent( window ) {};
    };
            
    class AEON_DLL WindowMoveEvent : public WindowEvent
    {
    public:
        WindowMoveEvent( Graphics::Window* window, 
                         uint32_t pos_x, uint32_t pos_y )
        : WindowEvent( window), m_pos_x( pos_x ), m_pos_y( pos_y ) {};
        
        uint32_t    x() const { return m_pos_x; }
        uint32_t    y() const { return m_pos_y; }
    private:
        uint32_t    m_pos_x;
        uint32_t    m_pos_y;
    };
}