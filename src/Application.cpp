#include <Core/Application.h>
#include <Events/ApplicationEvents.h>

#include <algorithm>

namespace aer
{
     Application::Application( const std::string& name, Arguments args )
    : _name( name ), _arguments( args )
    {
        loguru::init( args.Count(), args.Values() );
        loguru::add_file( _name.c_str(), loguru::FileMode::Truncate, loguru::Verbosity_MAX );
        
        s_instance = this;
    }

     Application::~Application( void )
    {
        LOG_IF_F( WARNING, !_events.empty(), "Unhandled events: %zu", _events.size() );
        if( _events.size() > 0 ) _events.clear();
    }

    void  Application::Run()
    {
        while( _running == true )
        {
            PollEvents();
            Update();
        }
    }

    void  Application::Update()
    {
        for( const auto& window : _windows )
        {
            window->PollEvents( _events, true );
            window->Update();
        }
    }

    void  Application::PollEvents()
    {
        for( auto& event : _events )
        {
            event->Dispatch< WindowCloseEvent     >( this, &Application::OnWindowClose     );
            event->Dispatch< WindowConfigureEvent >( this, &Application::OnWindowConfigure );
            event->Dispatch< WindowMinimizeEvent  >( this, &Application::OnWindowMinimize  );
            event->Dispatch< WindowFocusEvent     >( this, &Application::OnWindowFocus     );
            event->Dispatch< WindowUnfocusEvent   >( this, &Application::OnWindowUnfocus   );
            event->Dispatch< KeyDownEvent         >( this, &Application::OnKeyDown         );
            event->Dispatch< KeyUpEvent           >( this, &Application::OnKeyUp           );
            event->Dispatch< KeyHoldEvent         >( this, &Application::OnKeyHold         );
            event->Dispatch< MouseMoveEvent       >( this, &Application::OnMouseMove       );
            event->Dispatch< MouseScrollEvent     >( this, &Application::OnMouseScroll     );
            event->Dispatch< MouseDownEvent       >( this, &Application::OnMouseDown       );
            event->Dispatch< MouseDoubleEvent     >( this, &Application::OnMouseDouble     );
            event->Dispatch< MouseUpEvent         >( this, &Application::OnMouseUp         );
        }

        return _events.clear();
    }

    bool  Application::OnKeyDown( KeyDownEvent& event )
    {
        return true;
    }

    bool  Application::OnKeyUp( KeyUpEvent& event )
    {
        return true;
    }
    
    bool  Application::OnKeyHold( KeyHoldEvent& event )
    {
        return true;
    }
    
    bool  Application::OnMouseMove( MouseMoveEvent& event )
    {
        return true;
    }
  
    bool  Application::OnMouseScroll( MouseScrollEvent& event )
    {
        return true;
    }

    bool  Application::OnMouseDown( MouseDownEvent& event )
    {
        return true;
    }

    bool  Application::OnMouseDouble( MouseDoubleEvent& event )
    {
        return true;
    }
    
    bool  Application::OnMouseUp( MouseUpEvent& event )
    {
        return true;
    }

    bool  Application::OnWindowClose( WindowCloseEvent& event )
    {
        _windows.remove( event.window.load() );
        if( _windows.empty() ) Close();
        return true;
    }

    bool  Application::OnWindowConfigure( WindowConfigureEvent& event )
    {
        return true;
    }
  
    bool  Application::OnWindowMinimize( WindowMinimizeEvent& event )
    {
        _background = std::all_of( _windows.begin(), _windows.end(), []( const auto& w ){ return w->properties().minimized; } );
        return true;
    }

    bool  Application::OnWindowFocus( WindowFocusEvent& event )
    {
        _background = false;
        return true;
    }

    bool  Application::OnWindowUnfocus( WindowUnfocusEvent& event )
    {
        _background = std::all_of( _windows.begin(), _windows.end(), []( const auto& w ){ return w->properties().minimized; } );
        return true;
    }
}