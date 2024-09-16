#include <Core/Application.h>
#include <Events/ApplicationEvents.h>

#include <algorithm>

namespace aer
{
    AEON_API Application::Application( const std::string& name, Arguments args )
    : _name( name ), _arguments( args )
    {
        log::internal::init( args.Count(), args.Values() );
        log::internal::add_file( _name.c_str() );
        
        s_instance = this;
    }

    AEON_API Application::~Application( void )
    {
        AE_WARN_IF( !_events.empty(), "Unhandled events: %zu", _events.size() );
        if( _events.size() > 0 ) _events.clear();
    }

    void AEON_API Application::Run()
    {
        while( _running == true )
        {
            PollEvents();
            Update();
        }
    }

    void AEON_API Application::Update()
    {
        for( const auto& window : _windows )
        {
            window->PollEvents( _events, true );
            window->Update();
        }
    }

    void AEON_API Application::PollEvents()
    {
        for( auto& event : _events )
        {
            event->Dispatch< WindowCloseEvent    >( this, &Application::OnWindowClose    );
            event->Dispatch< WindowResizeEvent   >( this, &Application::OnWindowResize   );
            event->Dispatch< WindowMinimizeEvent >( this, &Application::OnWindowMinimize );
            event->Dispatch< WindowFocusEvent    >( this, &Application::OnWindowFocus    );
            event->Dispatch< WindowUnfocusEvent  >( this, &Application::OnWindowUnfocus  );
            event->Dispatch< KeyDownEvent        >( this, &Application::OnKeyDown        );
            event->Dispatch< KeyUpEvent          >( this, &Application::OnKeyUp          );
            event->Dispatch< KeyHoldEvent        >( this, &Application::OnKeyHold        );
            event->Dispatch< MouseMoveEvent      >( this, &Application::OnMouseMove      );
            event->Dispatch< MouseScrollEvent    >( this, &Application::OnMouseScroll    );
            event->Dispatch< MouseDownEvent      >( this, &Application::OnMouseDown      );
            event->Dispatch< MouseDoubleEvent    >( this, &Application::OnMouseDouble    );
            event->Dispatch< MouseUpEvent        >( this, &Application::OnMouseUp        );
        }

        return _events.clear();
    }

    bool AEON_API Application::OnKeyDown( KeyDownEvent& event )
    {
        return true;
    }

    bool AEON_API Application::OnKeyUp( KeyUpEvent& event )
    {
        return true;
    }
    
    bool AEON_API Application::OnKeyHold( KeyHoldEvent& event )
    {
        return true;
    }
    
    bool AEON_API Application::OnMouseMove( MouseMoveEvent& event )
    {
        return true;
    }
  
    bool AEON_API Application::OnMouseScroll( MouseScrollEvent& event )
    {
        return true;
    }

    bool AEON_API Application::OnMouseDown( MouseDownEvent& event )
    {
        return true;
    }

    bool AEON_API Application::OnMouseDouble( MouseDoubleEvent& event )
    {
        return true;
    }
    
    bool AEON_API Application::OnMouseUp( MouseUpEvent& event )
    {
        return true;
    }

    bool AEON_API Application::OnWindowClose( WindowCloseEvent& event )
    {
        _windows.remove( event.window().load() );
        if( _windows.empty() ) Close();
        return true;
    }

    bool AEON_API Application::OnWindowResize( WindowResizeEvent& event )
    {
        return true;
    }
  
    bool AEON_API Application::OnWindowMinimize( WindowMinimizeEvent& event )
    {
        _background = std::all_of( _windows.begin(), _windows.end(), []( const auto& w ){ return w->minimized(); } );
        return true;
    }

    bool AEON_API Application::OnWindowFocus( WindowFocusEvent& event )
    {
        _background = false;
        return true;
    }

    bool AEON_API Application::OnWindowUnfocus( WindowUnfocusEvent& event )
    {
        _background = std::all_of( _windows.begin(), _windows.end(), []( const auto& w ){ return w->minimized(); } );
        return true;
    }
}