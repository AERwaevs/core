#pragma once

#include <Base/Base.h>
#include <Base/Event.h>

#include <Input/KeyCodes.h>

namespace aer
{
    
class Window;   // forward declare

struct KeyEvent : public Event
{
    KeyEvent(auto in_window, auto in_key_base, auto in_key_modified, auto in_mod)
    : window(in_window), key_base(in_key_base), key_modified(in_key_modified), modifier(in_mod) {};

    spy_ptr<Window> window;
    aer::key_symbol      key_base;
    aer::key_symbol      key_modified;
    aer::key::mod        modifier;
};

struct KeyDownEvent : public KeyEvent
{
    KeyDownEvent(auto window, auto in_key_base, auto in_key_modified, auto in_mod)
    : KeyEvent(window, in_key_base, in_key_modified, in_mod) {};
};

struct KeyUpEvent : public KeyEvent
{
    KeyUpEvent(auto window, auto in_key_base, auto in_key_modified, auto in_mod)
    : KeyEvent(window, in_key_base, in_key_modified, in_mod) {};
};

struct KeyHoldEvent : public KeyEvent
{
    KeyHoldEvent(auto window, auto in_key_base, auto in_key_modified, auto in_mod, auto in_repeats)
    : KeyEvent(window, in_key_base, in_key_modified, in_mod), repeats(in_repeats) {};

    uint32_t repeats;
};

}