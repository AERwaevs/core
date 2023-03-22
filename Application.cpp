#include "Application.h"

namespace AEON
{
    AEON_API Application::Application( const String& name, Arguments args )
    : m_name( name ), m_arguments( args )
    {
        Log::Init(  args.Count(), 
                    args.Values() );
        Log::New(   name );
        
        s_instance = this;
    }

    AEON_API Application::~Application( void )
    {
        if( m_windows.size() > 0 ) m_windows.clear();
        if( m_events.size()  > 0 ) m_events.clear();
    }

    void AEON_API Application::Run()
    {
        while( m_running == true )
        {
            Update();
            PollEvents();
        }
    }

    void AEON_API Application::Close()
    {
        m_running = false;
    }

    void AEON_API Application::Update()
    {
        if( m_windows.size() == 0 ) Close();

        for( auto& window : m_windows )
        {
            window->PollEvents( m_events );
            window->Update();
        }
    }

    void AEON_API Application::PollEvents()
    {
        for( auto& event : m_events )
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
        m_events.clear();
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
        m_windows.remove( event.window() );
        return true;
    }
  
    bool AEON_API Application::OnWindowResize( WindowResizeEvent& event )
    {
        if( event.x() == 0 || event.y() == 0 )
        {
            m_minimized     = true;
            m_background    = true;
        }
        return true;
    }
  
    bool AEON_API Application::OnWindowMinimize( WindowMinimizeEvent& event )
    {
        m_minimized     = true;
        m_background    = true;
        return true;
    }

    bool AEON_API Application::OnWindowFocus( WindowFocusEvent& event )
    {
        m_minimized     = false;
        m_background    = false;
        return true;
    }

    bool AEON_API Application::OnWindowUnfocus( WindowUnfocusEvent& event )
    {
        m_background    = true;
        return true;
    }
}