#include "Application.h"

namespace AEON
{
    AEON_API Application::Application( const String& name, Arguments args )
    : _name( name ), _arguments( args )
    {
        Log::Init(  args.Count(), 
                    args.Values() );
        Log::New(   name );
        
        s_instance = this;
    }

    AEON_API Application::~Application( void )
    {
        if( _layers.size() > 0 ) _layers.clear();
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

    void AEON_API Application::Close()
    {
        _running = false;
    }

    void AEON_API Application::Update()
    {
        for( const auto& layer : _layers )
        {
            layer->PollEvents( _events );
            layer->OnUpdate();
        }

        if( _layers.size() == 0 ) Close();
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
        _events.clear();
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
        return true;
    }
  
    bool AEON_API Application::OnWindowResize( WindowResizeEvent& event )
    {
        if( event.x() == 0 || event.y() == 0 )
        {
            _minimized     = true;
            _background    = true;
        }
        return true;
    }
  
    bool AEON_API Application::OnWindowMinimize( WindowMinimizeEvent& event )
    {
        _minimized     = true;
        _background    = true;
        return true;
    }

    bool AEON_API Application::OnWindowFocus( WindowFocusEvent& event )
    {
        _minimized     = false;
        _background    = false;
        return true;
    }

    bool AEON_API Application::OnWindowUnfocus( WindowUnfocusEvent& event )
    {
        _background    = true;
        return true;
    }
}