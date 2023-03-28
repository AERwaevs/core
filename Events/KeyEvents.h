#pragma once

#include <Input/KeyCodes.h>
#include <Core/Events/WindowEvents.h>


namespace AEON
{
    class KeyEvent : public WindowEvent
    {
    public:
        KeyEvent( Graphics::Window* window, Key::ScanCode& code, Key::Code& key, Key::Mod& mod )
        : WindowEvent( window ), _code( code ), _key( key ), _mod( mod )
        {};

        Key::ScanCode   code() const { return _code; }
        Key::Code       key()  const { return _key; }
        Key::Mod        mod()  const { return _mod; }
    private:
        Key::ScanCode   _code;
        Key::Code       _key;
        Key::Mod        _mod;
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
                      uint32_t repeats ) 
        : KeyEvent( window, code, key, mod ), _repeats( repeats )
        {};

        uint32_t repeats() const { return _repeats; }
    private:
        uint32_t _repeats;
    };
}