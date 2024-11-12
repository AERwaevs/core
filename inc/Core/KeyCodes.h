#pragma once

#include <stdint.h>

namespace aer {
namespace key { using symbol = uint16_t; }

typedef enum : key::symbol
{
    KEY_Undefined       = 0x0,

    KEY_Space           = ' ',

    KEY_0               = '0',
    KEY_1               = '1',
    KEY_2               = '2',
    KEY_3               = '3',
    KEY_4               = '4',
    KEY_5               = '5',
    KEY_6               = '6',
    KEY_7               = '7',
    KEY_8               = '8',
    KEY_9               = '9',

    KEY_a               = 'a',
    KEY_b               = 'b',
    KEY_c               = 'c',
    KEY_d               = 'd',
    KEY_e               = 'e',
    KEY_f               = 'f',
    KEY_g               = 'g',
    KEY_h               = 'h',
    KEY_i               = 'i',
    KEY_j               = 'j',
    KEY_k               = 'k',
    KEY_l               = 'l',
    KEY_m               = 'm',
    KEY_n               = 'n',
    KEY_o               = 'o',
    KEY_p               = 'p',
    KEY_q               = 'q',
    KEY_r               = 'r',
    KEY_s               = 's',
    KEY_t               = 't',
    KEY_u               = 'u',
    KEY_v               = 'v',
    KEY_w               = 'w',
    KEY_x               = 'x',
    KEY_y               = 'y',
    KEY_z               = 'z',

    KEY_A               = 'A',
    KEY_B               = 'B',
    KEY_C               = 'C',
    KEY_D               = 'D',
    KEY_E               = 'E',
    KEY_F               = 'F',
    KEY_G               = 'G',
    KEY_H               = 'H',
    KEY_I               = 'I',
    KEY_J               = 'J',
    KEY_K               = 'K',
    KEY_L               = 'L',
    KEY_M               = 'M',
    KEY_N               = 'N',
    KEY_O               = 'O',
    KEY_P               = 'P',
    KEY_Q               = 'Q',
    KEY_R               = 'R',
    KEY_S               = 'S',
    KEY_T               = 'T',
    KEY_U               = 'U',
    KEY_V               = 'V',
    KEY_W               = 'W',
    KEY_X               = 'X',
    KEY_Y               = 'Y',
    KEY_Z               = 'Z',

    KEY_Exclaim         = '!',
    KEY_QuoteDouble     = '\"',
    KEY_Hash            = '#',
    KEY_Dollar          = '$',
    KEY_Percent         = '%',
    KEY_Ampersand       = '&',
    KEY_Quote           = '\'',
    KEY_Parenthesis_L   = '(',
    KEY_Parenthesis_R   = ')',
    KEY_Asterisk        = '*',
    KEY_Plus            = '+',
    KEY_Comma           = ',',
    KEY_Minus           = '-',
    KEY_Period          = '.',
    KEY_Slash           = '/',
    KEY_Colon           = ':',
    KEY_Semicolon       = ';',
    KEY_Less            = '<',
    KEY_Equals          = '=',
    KEY_Greater         = '>',
    KEY_Question        = '?',
    KEY_At              = '@',
    KEY_BracketSquare_L = '[',
    KEY_Backslash       = '\\',
    KEY_BracketSquare_R = ']',
    KEY_Caret           = '^',
    KEY_Underscore      = '_',
    KEY_Backquote       = '`',
    KEY_BracketCurly_L  = '{',
    KEY_Verticalslash   = '|',
    KEY_BracketCurly_R  = '}',
    KEY_Tilde           = '~',

    KEY_BackSpace       = 0xFF08, /* back space, back char */
    KEY_Tab             = 0xFF09,
    KEY_Linefeed        = 0xFF0A, /* Linefeed, LF */
    KEY_Clear           = 0xFF0B,
    KEY_Return          = 0xFF0D, /* Return, enter */
    KEY_Pause           = 0xFF13, /* Pause, hold */
    KEY_Scroll_Lock     = 0xFF14,
    KEY_Sys_Req         = 0xFF15,
    KEY_Escape          = 0xFF1B,
    KEY_Delete          = 0xFFFF, /* Delete, rubout */

    KEY_Home            = 0xFF50,
    KEY_Left            = 0xFF51, /* Move left, left arrow */
    KEY_Up              = 0xFF52, /* Move up, up arrow */
    KEY_Right           = 0xFF53, /* Move right, right arrow */
    KEY_Down            = 0xFF54, /* Move down, down arrow */
    KEY_Prior           = 0xFF55, /* Prior, previous */
    KEY_Page_Up         = 0xFF55,
    KEY_Next            = 0xFF56, /* Next */
    KEY_Page_Down       = 0xFF56,
    KEY_End             = 0xFF57, /* EOL */
    KEY_Begin           = 0xFF58, /* BOL */

    KEY_Select          = 0xFF60, /* Select, mark */
    KEY_Print           = 0xFF61,
    KEY_Execute         = 0xFF62, /* Execute, run, do */
    KEY_Insert          = 0xFF63, /* Insert, insert here */
    KEY_Undo            = 0xFF65, /* Undo, oops */
    KEY_Redo            = 0xFF66, /* redo, again */
    KEY_Menu            = 0xFF67, /* On Windows, this is VK_APPS, the context-menu key */
    KEY_Find            = 0xFF68, /* Find, search */
    KEY_Cancel          = 0xFF69, /* Cancel, stop, abort, exit */
    KEY_Help            = 0xFF6A, /* Help */
    KEY_Break           = 0xFF6B,
    KEY_Mode_switch     = 0xFF7E, /* Character set switch */
    KEY_Num_Lock        = 0xFF7F,

    KEY_KP_Space        = 0xFF80, /* space */
    KEY_KP_Tab          = 0xFF89,
    KEY_KP_Enter        = 0xFF8D, /* enter */
    KEY_KP_F1           = 0xFF91, /* PF1, KP_A, ... */
    KEY_KP_F2           = 0xFF92,
    KEY_KP_F3           = 0xFF93,
    KEY_KP_F4           = 0xFF94,
    KEY_KP_Home         = 0xFF95,
    KEY_KP_Left         = 0xFF96,
    KEY_KP_Up           = 0xFF97,
    KEY_KP_Right        = 0xFF98,
    KEY_KP_Down         = 0xFF99,
    KEY_KP_Prior        = 0xFF9A,
    KEY_KP_Page_Up      = 0xFF9A,
    KEY_KP_Next         = 0xFF9B,
    KEY_KP_Page_Down    = 0xFF9B,
    KEY_KP_End          = 0xFF9C,
    KEY_KP_Begin        = 0xFF9D,
    KEY_KP_Insert       = 0xFF9E,
    KEY_KP_Delete       = 0xFF9F,
    KEY_KP_Equal        = 0xFFBD, /* equals */
    KEY_KP_Multiply     = 0xFFAA,
    KEY_KP_Add          = 0xFFAB,
    KEY_KP_Separator    = 0xFFAC, /* separator, often comma */
    KEY_KP_Subtract     = 0xFFAD,
    KEY_KP_Decimal      = 0xFFAE,
    KEY_KP_Divide       = 0xFFAF,

    KEY_KP_0            = 0xFFB0,
    KEY_KP_1            = 0xFFB1,
    KEY_KP_2            = 0xFFB2,
    KEY_KP_3            = 0xFFB3,
    KEY_KP_4            = 0xFFB4,
    KEY_KP_5            = 0xFFB5,
    KEY_KP_6            = 0xFFB6,
    KEY_KP_7            = 0xFFB7,
    KEY_KP_8            = 0xFFB8,
    KEY_KP_9            = 0xFFB9,

    KEY_F1              = 0xFFBE,
    KEY_F2              = 0xFFBF,
    KEY_F3              = 0xFFC0,
    KEY_F4              = 0xFFC1,
    KEY_F5              = 0xFFC2,
    KEY_F6              = 0xFFC3,
    KEY_F7              = 0xFFC4,
    KEY_F8              = 0xFFC5,
    KEY_F9              = 0xFFC6,
    KEY_F10             = 0xFFC7,
    KEY_F11             = 0xFFC8,
    KEY_F12             = 0xFFC9,

    KEY_Shift_L         = 0xFFE1, /* Left shift */
    KEY_Shift_R         = 0xFFE2, /* Right shift */
    KEY_Control_L       = 0xFFE3, /* Left control */
    KEY_Control_R       = 0xFFE4, /* Right control */
    KEY_Caps_Lock       = 0xFFE5, /* Caps lock */
    KEY_Shift_Lock      = 0xFFE6, /* Shift lock */

    KEY_Meta_L          = 0xFFE7, /* Left meta / windows key */
    KEY_Meta_R          = 0xFFE8, /* Right meta / windows key / NOT A COPILOT KEY */
    KEY_Alt_L           = 0xFFE9, /* Left alt */
    KEY_Alt_R           = 0xFFEA, /* Right alt */
    KEY_Super_L         = 0xFFEB, /* Left super */
    KEY_Super_R         = 0xFFEC, /* Right super */
    KEY_Hyper_L         = 0xFFED, /* Left hyper */
    KEY_Hyper_R         = 0xFFEE  /* Right hyper */
} key_symbol;

namespace key{
    
typedef enum : symbol
{
    MOD_None     = 0B00000000,
    MOD_Shift    = 0B00000001,
    MOD_CapsLock = 0B00000010,
    MOD_Control  = 0B00000100,
    MOD_Alt      = 0B00001000,
    MOD_NumLock  = 0B00010000,
    MOD_Super    = 0B00100000,
    MOD_Hyper    = 0B01000000,
    MOD_Meta     = 0B10000000,
} mod;

/* Scancodes are from en_US keyboard layout */
typedef enum : symbol
{
    KB_None                 = 0,

    KB_A                    = 4,
    KB_B                    = 5,
    KB_C                    = 6,
    KB_D                    = 7,
    KB_E                    = 8,
    KB_F                    = 9,
    KB_G                    = 10,
    KB_H                    = 11,
    KB_I                    = 12,
    KB_J                    = 13,
    KB_K                    = 14,
    KB_L                    = 15,
    KB_M                    = 16,
    KB_N                    = 17,
    KB_O                    = 18,
    KB_P                    = 19,
    KB_Q                    = 20,
    KB_R                    = 21,
    KB_S                    = 22,
    KB_T                    = 23,
    KB_U                    = 24,
    KB_V                    = 25,
    KB_W                    = 26,
    KB_X                    = 27,
    KB_Y                    = 28,
    KB_Z                    = 29,
    KB_1                    = 30,
    KB_2                    = 31,
    KB_3                    = 32,
    KB_4                    = 33,
    KB_5                    = 34,
    KB_6                    = 35,
    KB_7                    = 36,
    KB_8                    = 37,
    KB_9                    = 38,
    KB_0                    = 39,

    KB_Escape               = 41,
    KB_Backspace            = 42,
    KB_Tab                  = 43,
    KB_Space                = 44,
    KB_Minus                = 45,
    KB_Equals               = 46,
    KB_LeftBracket          = 47,
    KB_RightBracket         = 48,
    KB_Backslash            = 49,
    KB_Semicolon            = 51,
    KB_Quote                = 52,
    KB_Grave                = 53,
    KB_Comma                = 54,
    KB_Period               = 55,
    KB_Slash                = 56,
    KB_CapsLock             = 57,

    KB_F1                   = 58,
    KB_F2                   = 59,
    KB_F3                   = 60,
    KB_F4                   = 61,
    KB_F5                   = 62,
    KB_F6                   = 63,
    KB_F7                   = 64,
    KB_F8                   = 65,
    KB_F9                   = 66,
    KB_F10                  = 67,
    KB_F11                  = 68,
    KB_F12                  = 69,

    KB_PrintScreen          = 70,
    KB_ScrollLock           = 71,
    KB_Pause                = 72,
    KB_Insert               = 73,
    KB_Home                 = 74,
    KB_PageUp               = 75,
    KB_Delete               = 76,
    KB_End                  = 77,
    KB_PageDown             = 78,
    KB_Right                = 79,
    KB_Left                 = 80,
    KB_Down                 = 81,
    KB_Up                   = 82,

    NP_NumLock              = 83,
    NP_Divide               = 84,
    NP_Multiply             = 85,
    NP_Subtract             = 86,
    NP_Add                  = 87,
    NP_Enter                = 88,
    NP_1                    = 89,
    NP_2                    = 90,
    NP_3                    = 91,
    NP_4                    = 92,
    NP_5                    = 93,
    NP_6                    = 94,
    NP_7                    = 95,
    NP_8                    = 96,
    NP_9                    = 97,
    NP_0                    = 98,
    NP_Decimal              = 99,

    KB_NonUSBackslash       = 100,

    NP_Equals               = 103,

    KB_F13                  = 104,
    KB_F14                  = 105,
    KB_F15                  = 106,
    KB_F16                  = 107,
    KB_F17                  = 108,
    KB_F18                  = 109,
    KB_F19                  = 110,
    KB_F20                  = 111,
    KB_F21                  = 112,
    KB_F22                  = 113,
    KB_F23                  = 114,
    KB_F24                  = 115,

    KB_Help                 = 117,
    KB_Menu                 = 118,
    KB_Mute                 = 127,
    KB_SysReq               = 154,
    KB_Return               = 158,

    NP_Clear                = 216,
    NP_Point                = 220,

    KB_LeftControl          = 224,
    KB_LeftShift            = 225,
    KB_LeftAlt              = 226,
    KB_LeftMenu             = 227,
    KB_RightControl         = 228,
    KB_RightShift           = 229,
    KB_RightAlt             = 230,
    KB_RightMenu            = 231
} scancode;

constexpr auto name( mod m ) noexcept
{
    switch ( m )
    {
        case MOD_None:            return "None";
        case MOD_Shift:           return "Shift";
        case MOD_CapsLock:        return "CapsLock";
        case MOD_Control:         return "Control";
        case MOD_Alt:             return "Alt";
        case MOD_NumLock:         return "NumLock";
        case MOD_Super:           return "Super";
        case MOD_Hyper:           return "Hyper";
        case MOD_Meta:            return "Meta";
        default:                  return "Undefined";
    }
}

constexpr auto name( scancode c ) noexcept
{
    switch( c )
    {
        case KB_None:           return "Code::None";

        case KB_A:              return "Code::A";
        case KB_B:              return "Code::B";
        case KB_C:              return "Code::C";
        case KB_D:              return "Code::D";
        case KB_E:              return "Code::E";
        case KB_F:              return "Code::F";
        case KB_G:              return "Code::G";
        case KB_H:              return "Code::H";
        case KB_I:              return "Code::I";
        case KB_J:              return "Code::J";
        case KB_K:              return "Code::K";
        case KB_L:              return "Code::L";
        case KB_M:              return "Code::M";
        case KB_N:              return "Code::N";
        case KB_O:              return "Code::O";
        case KB_P:              return "Code::P";
        case KB_Q:              return "Code::Q";
        case KB_R:              return "Code::R";
        case KB_S:              return "Code::S";
        case KB_T:              return "Code::T";
        case KB_U:              return "Code::U";
        case KB_V:              return "Code::V";
        case KB_W:              return "Code::W";
        case KB_X:              return "Code::X";
        case KB_Y:              return "Code::Y";
        case KB_Z:              return "Code::Z";
        case KB_1:              return "Code::1";
        case KB_2:              return "Code::2";
        case KB_3:              return "Code::3";
        case KB_4:              return "Code::4";
        case KB_5:              return "Code::5";
        case KB_6:              return "Code::6";
        case KB_7:              return "Code::7";
        case KB_8:              return "Code::8";
        case KB_9:              return "Code::9";
        case KB_0:              return "Code::0";

        case KB_Escape:         return "Code::Escape";
        case KB_Backspace:      return "Code::Backspace";
        case KB_Tab:            return "Code::Tab";
        case KB_Space:          return "Code::Space";
        case KB_Minus:          return "Code::Minus";
        case KB_Equals:         return "Code::Equals";
        case KB_LeftBracket:    return "Code::LeftBracket";
        case KB_RightBracket:   return "Code::RightBracket";
        case KB_Backslash:      return "Code::Backslash";
        case KB_Semicolon:      return "Code::Semicolon";
        case KB_Quote:          return "Code::Quote";
        case KB_Grave:          return "Code::Grave";
        case KB_Comma:          return "Code::Comma";
        case KB_Period:         return "Code::Period";
        case KB_Slash:          return "Code::Slash";
        case KB_CapsLock:       return "Code::CapsLock";

        case KB_F1:             return "Code::F1";
        case KB_F2:             return "Code::F2";
        case KB_F3:             return "Code::F3";
        case KB_F4:             return "Code::F4";
        case KB_F5:             return "Code::F5";
        case KB_F6:             return "Code::F6";
        case KB_F7:             return "Code::F7";
        case KB_F8:             return "Code::F8";
        case KB_F9:             return "Code::F9";
        case KB_F10:            return "Code::F10";
        case KB_F11:            return "Code::F11";
        case KB_F12:            return "Code::F12";

        case KB_PrintScreen:    return "Code::PrintScreen";
        case KB_ScrollLock:     return "Code::ScrollLock";
        case KB_Pause:          return "Code::Pause";
        case KB_Insert:         return "Code::Insert";
        case KB_Home:           return "Code::Home";
        case KB_PageUp:         return "Code::PageUp";
        case KB_Delete:         return "Code::Delete";
        case KB_End:            return "Code::End";
        case KB_PageDown:       return "Code::PageDown";
        case KB_Right:          return "Code::Right";
        case KB_Left:           return "Code::Left";
        case KB_Down:           return "Code::Down";
        case KB_Up:             return "Code::Up";

        case NP_NumLock:        return "Code::NumLock_NP";
        case NP_Divide:         return "Code::Divide_NP";
        case NP_Multiply:       return "Code::Multiply_NP";
        case NP_Subtract:       return "Code::Subtract_NP";
        case NP_Add:            return "Code::Add_NP";
        case NP_Enter:          return "Code::Enter_NP";
        case NP_1:              return "Code::1_NP";
        case NP_2:              return "Code::2_NP";
        case NP_3:              return "Code::3_NP";
        case NP_4:              return "Code::4_NP";
        case NP_5:              return "Code::5_NP";
        case NP_6:              return "Code::6_NP";
        case NP_7:              return "Code::7_NP";
        case NP_8:              return "Code::8_NP";
        case NP_9:              return "Code::9_NP";
        case NP_0:              return "Code::0_NP";
        case NP_Decimal:        return "Code::Decimal_NP";

        case KB_NonUSBackslash: return "Code::NonUSBackslash";

        case NP_Equals:         return "Code::Equals_NP";

        case KB_F13:            return "Code::F13";
        case KB_F14:            return "Code::F14";
        case KB_F15:            return "Code::F15";
        case KB_F16:            return "Code::F16";
        case KB_F17:            return "Code::F17";
        case KB_F18:            return "Code::F18";
        case KB_F19:            return "Code::F19";
        case KB_F20:            return "Code::F20";
        case KB_F21:            return "Code::F21";
        case KB_F22:            return "Code::F22";
        case KB_F23:            return "Code::F23";
        case KB_F24:            return "Code::F24";

        case KB_Help:           return "Code::Help";
        case KB_Menu:           return "Code::Menu";
        case KB_Mute:           return "Code::Mute";
        case KB_SysReq:         return "Code::SysReq";
        case KB_Return:         return "Code::Return";

        case NP_Clear:          return "Code::Clear_NP";
        case NP_Point:          return "Code::Point_NP";

        case KB_LeftControl:    return "Code::LeftControl";
        case KB_LeftShift:      return "Code::LeftShift";
        case KB_LeftAlt:        return "Code::LeftAlt";
        case KB_LeftMenu:       return "Code::LeftMenu";
        case KB_RightControl:   return "Code::RightControl";
        case KB_RightShift:     return "Code::RightShift";
        case KB_RightAlt:       return "Code::RightAlt";
        case KB_RightMenu:      return "Code::RightMenu";
        default:                return "Code::Unknown";
    }
}

enum old : symbol
{
    None                    = 0,
    Undefined               = 0,

    Zero                    = '0',
    One                     = '1',
    Two                     = '2',
    Three                   = '3',
    Four                    = '4',
    Five                    = '5',
    Six                     = '6',
    Seven                   = '7',
    Eight                   = '8',
    Nine                    = '9',

    a                       = 'a',
    b                       = 'b',
    c                       = 'c',
    d                       = 'd',
    e                       = 'e',
    f                       = 'f',
    g                       = 'g',
    h                       = 'h',
    i                       = 'i',
    j                       = 'j',
    k                       = 'k',
    l                       = 'l',
    m                       = 'm',
    n                       = 'n',
    o                       = 'o',
    p                       = 'p',
    q                       = 'q',
    r                       = 'r',
    s                       = 's',
    t                       = 't',
    u                       = 'u',
    v                       = 'v',
    w                       = 'w',
    x                       = 'x',
    y                       = 'y',
    z                       = 'z',

    A                       = 'A',
    B                       = 'B',
    C                       = 'C',
    D                       = 'D',
    E                       = 'E',
    F                       = 'F',
    G                       = 'G',
    H                       = 'H',
    I                       = 'I',
    J                       = 'J',
    K                       = 'K',
    L                       = 'L',
    M                       = 'M',
    N                       = 'N',
    O                       = 'O',
    P                       = 'P',
    Q                       = 'Q',
    R                       = 'R',
    S                       = 'S',
    T                       = 'T',
    U                       = 'U',
    V                       = 'V',
    W                       = 'W',
    X                       = 'X',
    Y                       = 'Y',
    Z                       = 'Z',

    Space                   = ' ',
    Grave                   = '`',
    Tilde                   = '~',
    ExclamationMark         = '!',
    At                      = '@',
    Hash                    = '#',
    Dollar                  = '$',
    Percent                 = '%',
    Caret                   = '^',
    Ampersand               = '&',
    Asterisk                = '*',
    LeftParenthesis         = '(',
    RightParenthesis        = ')',
    Underscore              = '_',
    Plus                    = '+',
    Minus                   = '-',
    Equals                  = '=',
    LeftBracket             = '[',
    RightBracket            = ']',
    BackSlash               = '\\',
    VerticalSlash           = '|',
    LeftCurlyBracket        = '{',
    RightCurlyBracket       = '}',
    Semicolon               = ';',
    Apostrophe              = '\'',
    Colon                   = ':',
    Quote                   = '"',
    Comma                   = ',',
    Period                  = '.',
    Slash                   = '/',
    Less                    = '<',
    Greater                 = '>',
    Question                = '?',

    F1                      = 0xFF01,
    F2                      = 0xFF02,
    F3                      = 0xFF03,
    F4                      = 0xFF04,
    F5                      = 0xFF05,
    F6                      = 0xFF06,
    F7                      = 0xFF07,
    F8                      = 0xFF08,
    F9                      = 0xFF09,
    F10                     = 0xFF0A,
    F11                     = 0xFF0B,
    F12                     = 0xFF0C,

    Backspace               = 0xFF0D,
    Tab                     = 0xFF0E,
    Enter                   = 0xFF0F,
    Escape                  = 0xFFA1,
    CapsLock                = 0xFFA2,

    PrintScreen             = 0xFFA3,
    PauseBreak              = 0xFFA4,
    ScrollLock              = 0xFFA5,

    Insert                  = 0xFFA6,
    Home                    = 0xFFA7,
    PageUp                  = 0xFFA8,
    PageDown                = 0xFFA9,
    Delete                  = 0xFFAA,
    End                     = 0xFFAB,

    Left                    = 0xFFAC,
    Up                      = 0xFFAD,
    Right                   = 0xFFAE,
    Down                    = 0xFFAF,

    NumLock_NP              = 0xFFB0,
    Enter_NP                = 0xFFB1,

    Left_NP                 = 0xFFB3,
    Up_NP                   = 0xFFB4,
    Right_NP                = 0xFFB5,
    Down_NP                 = 0xFFB6,

    Insert_NP               = 0xFFBA,
    Home_NP                 = 0xFFB2,
    PageUp_NP               = 0xFFB7,
    PageDown_NP             = 0xFFB8,
    Delete_NP               = 0xFFBB,
    End_NP                  = 0xFFB9,

    Equals_NP               = 0xFFBC,
    Multiply_NP             = 0xFFBD,
    Add_NP                  = 0xFFBE,
    Subtract_NP             = 0xFFBF,
    Decimal_NP              = 0xFFC0,
    Divide_NP               = 0xFFC1,

    Zero_NP                 = 0xFFC2,
    One_NP                  = 0xFFC3,
    Two_NP                  = 0xFFC4,
    Three_NP                = 0xFFC5,
    Four_NP                 = 0xFFC6,
    Five_NP                 = 0xFFC7,
    Six_NP                  = 0xFFC8,
    Seven_NP                = 0xFFC9,
    Eight_NP                = 0xFFCA,
    Nine_NP                 = 0xFFCB,

    Shift_L                 = 0xFFCC,
    Shift_R                 = 0xFFCD,
    Control_L               = 0xFFCE,
    Control_R               = 0xFFCF,
    Alt_L                   = 0xFFD0,
    Alt_R                   = 0xFFD1,

    Menu_L                  = 0xFFD2,
    Menu_R                  = 0xFFD3
};

}

} // namespace aer::key

constexpr inline auto to_string( aer::key::symbol sym )
{
    using namespace aer;
    switch( sym )
    {
        case KEY_Undefined:        return "Undefined";

        case KEY_0:                return "0";
        case KEY_1:                return "1";
        case KEY_2:                return "2";
        case KEY_3:                return "3";
        case KEY_4:                return "4";
        case KEY_5:                return "5";
        case KEY_6:                return "6";
        case KEY_7:                return "7";
        case KEY_8:                return "8";
        case KEY_9:                return "9";

        case KEY_a:                return "a";
        case KEY_b:                return "b";
        case KEY_c:                return "c";
        case KEY_d:                return "d";
        case KEY_e:                return "e";
        case KEY_f:                return "f";
        case KEY_g:                return "g";
        case KEY_h:                return "h";
        case KEY_i:                return "i";
        case KEY_j:                return "j";
        case KEY_k:                return "k";
        case KEY_l:                return "l";
        case KEY_m:                return "m";
        case KEY_n:                return "n";
        case KEY_o:                return "o";
        case KEY_p:                return "p";
        case KEY_q:                return "q";
        case KEY_r:                return "r";
        case KEY_s:                return "s";
        case KEY_t:                return "t";
        case KEY_u:                return "u";
        case KEY_v:                return "v";
        case KEY_w:                return "w";
        case KEY_x:                return "x";
        case KEY_y:                return "y";
        case KEY_z:                return "z";

        case KEY_A:                return "A";
        case KEY_B:                return "B";
        case KEY_C:                return "C";
        case KEY_D:                return "D";
        case KEY_E:                return "E";
        case KEY_F:                return "F";
        case KEY_G:                return "G";
        case KEY_H:                return "H";
        case KEY_I:                return "I";
        case KEY_J:                return "J";
        case KEY_K:                return "K";
        case KEY_L:                return "L";
        case KEY_M:                return "M";
        case KEY_N:                return "N";
        case KEY_O:                return "O";
        case KEY_P:                return "P";
        case KEY_Q:                return "Q";
        case KEY_R:                return "R";
        case KEY_S:                return "S";
        case KEY_T:                return "T";
        case KEY_U:                return "U";
        case KEY_V:                return "V";
        case KEY_W:                return "W";
        case KEY_X:                return "X";
        case KEY_Y:                return "Y";
        case KEY_Z:                return "Z";

        case KEY_Space:            return " ";
        case KEY_Backquote:        return "`";
        case KEY_Tilde:            return "~";
        case KEY_Exclaim:          return "!";
        case KEY_At:               return "@";
        case KEY_Hash:             return "#";
        case KEY_Dollar:           return "$";
        case KEY_Percent:          return "%";
        case KEY_Caret:            return "^";
        case KEY_Ampersand:        return "&";
        case KEY_Asterisk:         return "*";
        case KEY_Parenthesis_L:    return "(";
        case KEY_Parenthesis_R:    return ")";
        case KEY_Underscore:       return "_";
        case KEY_Plus:             return "+";
        case KEY_Minus:            return "-";
        case KEY_Equals:           return "=";
        case KEY_BracketSquare_L:  return "[";
        case KEY_BracketSquare_R:  return "]";
        case KEY_Backslash:        return "\\";
        case KEY_Verticalslash:    return "|";
        case KEY_BracketCurly_L:   return "{";
        case KEY_BracketCurly_R:   return "}";
        case KEY_Semicolon:        return ";";
        case KEY_Quote:            return "\'";
        case KEY_Colon:            return ":";
        case KEY_QuoteDouble:      return "\"";
        case KEY_Comma:            return ",";
        case KEY_Period:           return ".";
        case KEY_Slash:            return "/";
        case KEY_Less:             return "<";
        case KEY_Greater:          return ">";
        case KEY_Question:         return "?";

        case KEY_F1:               return "F1";
        case KEY_F2:               return "F2";
        case KEY_F3:               return "F3";
        case KEY_F4:               return "F4";
        case KEY_F5:               return "F5";
        case KEY_F6:               return "F6";
        case KEY_F7:               return "F7";
        case KEY_F8:               return "F8";
        case KEY_F9:               return "F9";
        case KEY_F10:              return "F10";
        case KEY_F11:              return "F11";
        case KEY_F12:              return "F12";

        case KEY_BackSpace:        return "Backspace";
        case KEY_Tab:              return "Tab";
        case KEY_Return:           return "Enter";
        case KEY_Escape:           return "Escape";
        case KEY_Caps_Lock:        return "CapsLock";

        case KEY_Print:            return "PrintScreen";
        case KEY_Pause:            return "PauseBreak";
        case KEY_Scroll_Lock:      return "ScrollLock";

        case KEY_Insert:           return "Insert";
        case KEY_Home:             return "Home";
        case KEY_Page_Up:          return "PageUp";
        case KEY_Page_Down:        return "PageDown";
        case KEY_Delete:           return "Delete";
        case KEY_End:              return "End";

        case KEY_Left:             return "Left";
        case KEY_Up:               return "Up";
        case KEY_Right:            return "Right";
        case KEY_Down:             return "Down";

        case KEY_Num_Lock:         return "NumLock_NP";
        case KEY_KP_Enter:         return "Enter_NP";
        case KEY_KP_Home:          return "Home_NP";
        case KEY_KP_Left:          return "Left_NP";
        case KEY_KP_Up:            return "Up_NP";
        case KEY_KP_Right:         return "Right_NP";
        case KEY_KP_Down:          return "Down_NP";
        case KEY_KP_Page_Up:       return "PageUp_NP";
        case KEY_KP_Page_Down:     return "PageDown_NP";
        case KEY_KP_End:           return "End_NP";
        case KEY_KP_Insert:        return "Insert_NP";
        case KEY_KP_Delete:        return "Delete_NP";
        case KEY_KP_Equal:         return "Equals_NP";
        case KEY_KP_Multiply:      return "Multiply_NP";
        case KEY_KP_Add:           return "Add_NP";
        case KEY_KP_Subtract:      return "Subtract_NP";
        case KEY_KP_Decimal:       return "Decimal_NP";
        case KEY_KP_Divide:        return "Divide_NP"; 
        case KEY_KP_0:             return "Zero_NP";
        case KEY_KP_1:             return "One_NP";
        case KEY_KP_2:             return "Two_NP";
        case KEY_KP_3:             return "Three_NP";
        case KEY_KP_4:             return "Four_NP";
        case KEY_KP_5:             return "Five_NP";
        case KEY_KP_6:             return "Six_NP";
        case KEY_KP_7:             return "Seven_NP";
        case KEY_KP_8:             return "Eight_NP";
        case KEY_KP_9:             return "Nine_NP";

        case KEY_Shift_L:         return "Shift_L";
        case KEY_Shift_R:         return "Shift_R";
        case KEY_Control_L:       return "Control_L";
        case KEY_Control_R:       return "Control_R";
        case KEY_Alt_L:           return "Alt_L";
        case KEY_Alt_R:           return "Alt_R";
        case KEY_Meta_L:          return "Meta_L";
        case KEY_Meta_R:          return "Meta_R";
        case KEY_Super_L:         return "Super_L";
        case KEY_Super_R:         return "Super_R";
        case KEY_Hyper_L:         return "Hyper_L";
        case KEY_Hyper_R:         return "Hyper_R";
        
        case KEY_Clear:           return "Clear";
        case KEY_Linefeed:        return "Linefeed";
        case KEY_Sys_Req:         return "SysReq";
        case KEY_Cancel:          return "Cancel";
        case KEY_Break:           return "Break";
        case KEY_Mode_switch:     return "ModeSwitch";
        case KEY_Select:          return "Select";
        case KEY_Execute:         return "Execute";
        case KEY_Undo:            return "Undo";
        case KEY_Redo:            return "Redo";
        case KEY_Find:            return "Find";
        case KEY_Help:            return "Help";
        case KEY_Menu:            return "Menu";
        case KEY_KP_Space:        return "Space_NP";
        case KEY_KP_Tab:          return "Tab_NP";
        case KEY_KP_F1:           return "F1_NP";
        case KEY_KP_F2:           return "F2_NP";
        case KEY_KP_F3:           return "F3_NP";
        case KEY_KP_F4:           return "F4_NP";
        case KEY_KP_Begin:        return "Begin_NP";
        case KEY_KP_Separator:    return "Separator_NP";
        default:                  return "Unknown";
    }
}