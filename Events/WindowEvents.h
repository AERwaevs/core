#pragma once

#include <Base/Base.h>

#include <Core/Event.h>

namespace AEON
{
    class Window;   // forward declare

    class AEON_DLL WindowEvent : public Inherit< Event, WindowEvent >
    {
    public:
        WindowEvent( Window* window ) : m_window( window ) {};
        
        Observer<Window>  window() const { return m_window; }
    private:
        Observer<Window>  m_window;
    };

    class AEON_DLL WindowCloseEvent : public Inherit< WindowEvent, WindowCloseEvent >
    {
    public:
        WindowCloseEvent( Window* window ) : Inherit( window ) {};
    };

    class AEON_DLL WindowResizeEvent : public Inherit< WindowEvent, WindowResizeEvent >
    {
    public:
        WindowResizeEvent( Window* window, 
                           uint32_t size_x, uint32_t  size_y ) 
        : Inherit( window ), m_size_x( size_x ), m_size_y( size_y )
        {};

        uint32_t    x() const { return m_size_x; }
        uint32_t    y() const { return m_size_y; }
    private:
        uint32_t    m_size_x;
        uint32_t    m_size_y;
    };

    class AEON_DLL WindowMinimizeEvent : public Inherit< WindowEvent, WindowMinimizeEvent >
    {
    public:
        WindowMinimizeEvent( Window* window ) : Inherit( window ) {};
    };
    
    class AEON_DLL WindowMaximizeEvent : public Inherit< WindowEvent, WindowMaximizeEvent >
    {
    public:
        WindowMaximizeEvent( Window* window ) : Inherit( window ) {};
    };
        
    class AEON_DLL WindowFocusEvent : public Inherit< WindowEvent, WindowFocusEvent >
    {
    public:
        WindowFocusEvent( Window* window ) : Inherit( window ) {};
    };
            
    class AEON_DLL WindowUnfocusEvent : public Inherit< WindowEvent, WindowUnfocusEvent >
    {
    public:
        WindowUnfocusEvent( Window* window ) : Inherit( window ) {};
    };
            
    class AEON_DLL WindowMoveEvent : public Inherit< WindowEvent, WindowMoveEvent >
    {
    public:
        WindowMoveEvent( Window* window, 
                         uint32_t pos_x, uint32_t pos_y )
        : Inherit( window), m_pos_x( pos_x ), m_pos_y( pos_y ) {};
        
        uint32_t    x() const { return m_pos_x; }
        uint32_t    y() const { return m_pos_y; }
    private:
        uint32_t    m_pos_x;
        uint32_t    m_pos_y;
    };
}