#pragma once

#include "Arguments.h"
#include "Layer.h"
#include "Event.h"
#include "Events/WindowEvents.h"
#include "Events/KeyEvents.h"
#include "Events/MouseEvents.h"

#include <Graphics/Renderer.h>
#include <Graphics/Window.h>

namespace AEON
{
    class Application : public IEventListener
    {
        using Renderer = Graphics::Renderer;
        using Windows  = Graphics::Windows;

    public:     
                Application( const String& name = "AEON", Arguments args = Arguments() );
        virtual ~Application();

        static  Application&    instance()   { return *s_instance;   }
                Arguments       arguments()  { return  _arguments;  }
                String          name()       { return  _name;       }
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
                Arguments           _arguments;
                String              _name;
                Windows             _windows;
                Events              _events;
                LayerStack          _layers;
    private:
                bool                _running       = true;
                bool                _background    = false;
                bool                _minimized     = false;

        static inline Application*  s_instance;
    };
}