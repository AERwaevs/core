#pragma once

#include <stdint.h>

namespace aer::Mouse
{

typedef enum : uint8_t
{
    None        = 0,
    Primary     = 1 << 0,
    Secondary   = 1 << 1,
    Tertiary    = 1 << 2,
    Auxilliary1 = 1 << 3,
    Auxilliary2 = 1 << 4,
    Left        = Primary,
    Right       = Secondary,
    Middle      = Tertiary,
    Front       = Auxilliary2,
    Back        = Auxilliary1
} Code;


}