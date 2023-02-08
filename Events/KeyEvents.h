#pragma once

#include <Input/KeyCodes.h>
#include <Core/Events/WindowEvents.h>


namespace AEON
{
    class AEON_DLL KeyEvent : public WindowEvent
    {
    public:
        KeyEvent( Window* window, Key::ScanCode& code, Key::Code& key, Key::Mod& mod )
        : WindowEvent( window ), m_code( code ), m_key( key ), m_mod( mod )
        {};

        Key::ScanCode   code() const { return m_code; }
        Key::Code       key()  const { return m_key; }
        Key::Mod        mod()  const { return m_mod; }
    private:
        Key::ScanCode   m_code;
        Key::Code       m_key;
        Key::Mod        m_mod;
    };

    class AEON_DLL KeyDownEvent : public KeyEvent
    {
    public:
        KeyDownEvent( Window* window, Key::ScanCode& code, Key::Code& key, Key::Mod& mod )
        : KeyEvent( window, code, key, mod ) 
        {};
    };

    class AEON_DLL KeyUpEvent : public KeyEvent
    {
    public:
        KeyUpEvent( Window* window, Key::ScanCode& code, Key::Code& key, Key::Mod& mod )
        : KeyEvent( window, code, key, mod ) 
        {};
    };

    class AEON_DLL KeyHoldEvent : public KeyEvent
    {
    public:
        KeyHoldEvent( Window* window, Key::ScanCode& code, Key::Code& key, Key::Mod& mod,
                      uint32_t repeat_count ) 
        : KeyEvent( window, code, key, mod ), m_repeat_count( repeat_count ) 
        {};

        uint32_t repeats() const { return m_repeat_count; }
    private:
        uint32_t m_repeat_count;
    };
}