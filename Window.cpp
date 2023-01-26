#include <Core/Window.h>

namespace AEON
{
    
void AEON_API Window::Update()
{
    while( m_viewport->AdvanceFrame() )
    {
        m_viewport->Update();
        m_viewport->Present();
    }
}
    
} // namespace AEON::Graphics
