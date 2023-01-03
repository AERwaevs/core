#pragma once

#include <Input/KeyCodes.h>
#include <Core/Events/WindowEvents.h>


namespace AEON
{
    class AEON_DLL KeyEvent : public Inherit< WindowEvent, KeyEvent >
    {
    public:
        KeyEvent( Window* window, Key::ScanCode& code, Key::Code& key, Key::Mod& mod )
        : Inherit( window ), m_code( code ), m_key( key ), m_mod( mod )
        {};

        Key::Mod        code() const { return m_mod; }
        Key::Code       key()  const { return m_key; }
        Key::Mod        mod()  const { return m_mod; }
    private:
        Key::ScanCode   m_code;
        Key::Code       m_key;
        Key::Mod        m_mod;
    };

    class AEON_DLL KeyDownEvent : public Inherit< KeyEvent, KeyDownEvent >
    {
    public:
        KeyDownEvent( Window* window, Key::ScanCode& code, Key::Code& key, Key::Mod& mod )
        : Inherit( window, code, key, mod ) 
        {};
    };

    class AEON_DLL KeyUpEvent : public Inherit< KeyEvent, KeyUpEvent >
    {
    public:
        KeyUpEvent( Window* window, Key::ScanCode& code, Key::Code& key, Key::Mod& mod )
        : Inherit( window, code, key, mod ) 
        {};
    };

    class AEON_DLL KeyHoldEvent : public Inherit< KeyEvent, KeyHoldEvent >
    {
    public:
        KeyHoldEvent( Window* window, Key::ScanCode& code, Key::Code& key, Key::Mod& mod,
                      uint32_t repeat_count ) 
        : Inherit( window, code, key, mod ), m_repeat_count( repeat_count ) 
        {};

        uint32_t repeats() const { return m_repeat_count; }
    private:
        uint32_t m_repeat_count;
    };
}