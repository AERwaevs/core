#pragma once

#include <Base/Base.h>

#include "Event.h"

namespace AEON
{

class Layer : public Object< Layer >
{
public:
            Layer( const std::string& name = "Layer" ) : _name( name ) {};
    virtual ~Layer() = default;

    virtual void OnAttach();
    virtual void OnDetach();
    virtual void OnUpdate();
    virtual bool OnEvent( Event& event );

protected:
    std::string _name;
};

using Layers = std::vector<ref_ptr<Layer>>;

//typedef ref_ptr<layer_t> Layer;

} // namespace AEON