#pragma once

#include <Base/Base.h>

namespace AEON
{
    namespace Mouse
    {
        using Symbol = uint8_t;

        BETTER_ENUM( Code, Symbol,
            None        = 0,
            Left        = BIT( 0 ),
            Right       = BIT( 1 ),
            Middle      = BIT( 2 ),
            Side1       = BIT( 3 ),
            Side2       = BIT( 4 ),
            Button5     = BIT( 5 ),
            Button6     = BIT( 6 ),
            Button7     = BIT( 7 )
        );
    }
}