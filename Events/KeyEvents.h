#pragma once

#include <Core/KeyCodes.h>
#include <Core/Events/WindowEvents.h>


namespace AEON
{
    class AEON_DLL KeyEvent : public Inherit< WindowEvent, KeyEvent >
    {
    public:
        KeyEvent( Window* window, Key::Code& key, Key::Code& modified_key, Key::Mod& mod )
        : Inherit( window ), m_key( key ), m_modified_key( modified_key ), m_mod( mod )
        {};

        Key::Code       key()  const { return /*( m_mod == +Key::Mod::Shift    ) ||
                                              ( m_mod == +Key::Mod::CapsLock ) 
                                              ? m_modified_key
                                              : */ m_key; }
        Key::Mod        mod()  const { return m_mod; }
    private:
        Key::Code       m_key;
        Key::Mod        m_mod;
        Key::Code       m_modified_key;
    };

    class AEON_DLL KeyDownEvent : public Inherit< KeyEvent, KeyDownEvent >
    {
    public:
        KeyDownEvent( Window* window, Key::Code& key, Key::Code& modified_key, Key::Mod& mod )
        : Inherit( window, key, modified_key, mod ) 
        {};
    };

    class AEON_DLL KeyUpEvent : public Inherit< KeyEvent, KeyUpEvent >
    {
    public:
        KeyUpEvent( Window* window, Key::Code& key, Key::Code& modified_key, Key::Mod& mod ) 
        : Inherit( window, key, modified_key, mod ) 
        {};
    };

    class AEON_DLL KeyHoldEvent : public Inherit< KeyEvent, KeyHoldEvent >
    {
    public:
        KeyHoldEvent( Window* window, Key::Code& key, Key::Code& modified_key, Key::Mod& mod, 
                      uint32_t repeat_count ) 
        : Inherit( window, key, modified_key, mod ), m_repeat_count( repeat_count ) 
        {};

        uint32_t repeats() const { return m_repeat_count; }
    private:
        uint32_t m_repeat_count;
    };
}