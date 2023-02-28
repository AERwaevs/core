#pragma once

#include <Core/Arguments.h>
#include <Core/Events/WindowEvents.h>
#include <Core/Events/KeyEvents.h>
#include <Core/Events/MouseEvents.h>

#include <Graphics/Renderer.h>
#include <Core/Window.h>

namespace AEON
{
    class Application
    {
        using Renderer = Graphics::Renderer;
        using Windows  = Graphics::Windows;

    public:     
                Application( const String& name = "AEON", Arguments args = Arguments() );
        virtual ~Application();

        static  Application&    instance()   { return *s_instance;   }
                Windows&        windows()    { return  m_windows;    }
                Arguments       arguments()  { return  m_arguments;  }
                String          name()       { return  m_name;       }
    protected:
                void            Close();
        virtual void            Update();
        virtual bool            OnKeyDown(        KeyDownEvent&        event );
        virtual bool            OnKeyUp(          KeyUpEvent&          event );
        virtual bool            OnKeyHold(        KeyHoldEvent&        event );
        virtual bool            OnMouseMove(      MouseMoveEvent&      event );
        virtual bool            OnMouseScroll(    MouseScrollEvent&    event );
        virtual bool            OnMouseDown(      MouseDownEvent&      event );
        virtual bool            OnMouseDouble(    MouseDoubleEvent&    event );
        virtual bool            OnMouseUp(        MouseUpEvent&        event );
        virtual bool            OnWindowClose(    WindowCloseEvent&    event );
        virtual bool            OnWindowResize(   WindowResizeEvent&   event );
        virtual bool            OnWindowMinimize( WindowMinimizeEvent& event );
        virtual bool            OnWindowFocus(    WindowFocusEvent&    event );
        virtual bool            OnWindowUnfocus(  WindowUnfocusEvent&  event );
    private:
                void            Run();
                void            PollEvents();
    private:
        friend  int             EntryPoint( int argc, char** argv );
    protected:
                Arguments           m_arguments;
                String              m_name;
                Windows             m_windows;
                Events              m_events;
    private:
                bool                m_running       = true;
                bool                m_background    = false;
                bool                m_minimized     = false;

        static inline Application*  s_instance;
    };
}