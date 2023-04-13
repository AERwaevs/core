#pragma once

#include <Base/Base.h>

#include "../Event.h"

namespace AEON
{

struct LayerEvent : Event
{
    LayerEvent( Layer* layer ) : _layer( layer ) {};
    
    spy_ptr<Layer>  layer() const { return _layer; }
protected:
    spy_ptr<Layer> _layer;
};

struct LayerPopEvent : public LayerEvent
{
    LayerPopEvent( Layer* layer ) : LayerEvent( layer ) {};
};

} // namespace AEON
