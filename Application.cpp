#include <Core/Application.h>

#include <Graphics/Renderer.h>

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
        for( auto& window : m_windows )
        {
            window->PollEvents( m_events );
            window->Update();

        }

        if( m_windows.size() == 0 ) Close();
    }

    void AEON_API Application::PollEvents()
    {
        for( auto& event : m_events )
        {
            event->Dispatch< WindowCloseEvent    >( BIND_WITH_ARGS( OnWindowClose    ) );
            event->Dispatch< WindowResizeEvent   >( BIND_WITH_ARGS( OnWindowResize   ) );
            event->Dispatch< WindowMinimizeEvent >( BIND_WITH_ARGS( OnWindowMinimize ) );
            event->Dispatch< WindowFocusEvent    >( BIND_WITH_ARGS( OnWindowFocus    ) );
            event->Dispatch< WindowUnfocusEvent  >( BIND_WITH_ARGS( OnWindowUnfocus  ) );
            event->Dispatch< KeyDownEvent        >( BIND_WITH_ARGS( OnKeyDown        ) );
            event->Dispatch< KeyUpEvent          >( BIND_WITH_ARGS( OnKeyUp          ) );
            event->Dispatch< KeyHoldEvent        >( BIND_WITH_ARGS( OnKeyHold        ) );
            event->Dispatch< MouseMoveEvent      >( BIND_WITH_ARGS( OnMouseMove      ) );
            event->Dispatch< MouseScrollEvent    >( BIND_WITH_ARGS( OnMouseScroll    ) );
            event->Dispatch< MouseDownEvent      >( BIND_WITH_ARGS( OnMouseDown      ) );
            event->Dispatch< MouseDoubleEvent    >( BIND_WITH_ARGS( OnMouseDouble    ) );
            event->Dispatch< MouseUpEvent        >( BIND_WITH_ARGS( OnMouseUp        ) );
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