#pragma once

#include <Base/Event.h>
#include <Base/EventListener.h>

#include <Events/KeyEvents.h>
#include <Events/MouseEvents.h>
#include <Events/WindowEvents.h>

#include <Graphics/Renderer.h>
#include <Graphics/Window.h>

#include "Arguments.h"

namespace aer
{
    class Application : protected IEventListener<Application>
    {
        using Renderer = Renderer;
        using Windows  = Windows;

    public:     
                Application( const std::string& name = "AER", Arguments args = Arguments() );
        virtual ~Application();

        static  Application&    instance()   { return *s_instance;  }
                Arguments       arguments()  { return  _arguments;  }
                std::string          name()  { return  _name;       }
    protected:
        inline  void            Close()      { _running = false;    }
        virtual void            Update();
        virtual bool            OnKeyDown(         KeyDownEvent&         );
        virtual bool            OnKeyUp(           KeyUpEvent&           );
        virtual bool            OnKeyHold(         KeyHoldEvent&         );
        virtual bool            OnMouseMove(       MouseMoveEvent&       );
        virtual bool            OnMouseScroll(     MouseScrollEvent&     );
        virtual bool            OnMouseDown(       MouseDownEvent&       );
        virtual bool            OnMouseDouble(     MouseDoubleEvent&     );
        virtual bool            OnMouseUp(         MouseUpEvent&         );
        virtual bool            OnWindowClose(     WindowCloseEvent&     );
        virtual bool            OnWindowConfigure( WindowConfigureEvent& );
        virtual bool            OnWindowMinimize(  WindowMinimizeEvent&  );
        virtual bool            OnWindowFocus(     WindowFocusEvent&     );
        virtual bool            OnWindowUnfocus(   WindowUnfocusEvent&   );
    private:
                void            Run();
                void            PollEvents();
    private:
        friend  int             EntryPoint( int, char** );
    protected:
                Arguments           _arguments;
                std::string         _name;
                Windows             _windows;
    private:
                bool                _running       = true;
                bool                _background    = false;

        static inline Application*  s_instance;
    };
}