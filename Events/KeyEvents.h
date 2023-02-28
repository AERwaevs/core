#pragma once

#include <Input/KeyCodes.h>
#include <Core/Events/WindowEvents.h>


namespace AEON
{
    class KeyEvent : public WindowEvent
    {
    public:
        KeyEvent( Graphics::Window* window, Key::ScanCode& code, Key::Code& key, Key::Mod& mod )
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

    class KeyDownEvent : public KeyEvent
    {
    public:
        KeyDownEvent( Graphics::Window* window, Key::ScanCode& code, Key::Code& key, Key::Mod& mod )
        : KeyEvent( window, code, key, mod ) 
        {};
    };

    class KeyUpEvent : public KeyEvent
    {
    public:
        KeyUpEvent( Graphics::Window* window, Key::ScanCode& code, Key::Code& key, Key::Mod& mod )
        : KeyEvent( window, code, key, mod ) 
        {};
    };

    class KeyHoldEvent : public KeyEvent
    {
    public:
        KeyHoldEvent( Graphics::Window* window, Key::ScanCode& code, Key::Code& key, Key::Mod& mod,
                      uint32_t repeat_count ) 
        : KeyEvent( window, code, key, mod ), m_repeat_count( repeat_count ) 
        {};

        uint32_t repeats() const { return m_repeat_count; }
    private:
        uint32_t m_repeat_count;
    };
}