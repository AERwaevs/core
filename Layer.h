#pragma once

#include <Base/Base.h>

#include "Event.h"
#include "EventListener.h"

namespace AEON
{

class Layer : public virtual Object, public Implements< Layer, IEventListener >

{
public:
            Layer( const std::string& name = "Layer" ) : _name( name ) {};
    virtual ~Layer() = default;

    virtual void OnAttach() = 0;
    virtual void OnDetach() = 0;
    virtual void OnUpdate() = 0;

    const std::string& name() const { return _name; }

protected:
    std::string _name;
};

using Layers = std::vector<ref_ptr<Layer>>;

class LayerStack
{
public:
    friend class Application;
    
    LayerStack() = default;
    LayerStack( Layers layers ) : _layers{ layers } {}
    ~LayerStack() { for( auto& layer : _layers ){ layer->OnDetach(); } }

    const size_t size() const { return _layers.size(); }
    void clear()
    {
        auto it = _layers.begin();
        while( it != _layers.end() )
        {
            it->get()->OnDetach();
            it = _layers.erase( it );
        }
    }
    
    std::vector<ref_ptr<Layer>>::iterator               begin()        { return _layers.begin(); }
    std::vector<ref_ptr<Layer>>::iterator               end()          { return _layers.end(); }
    std::vector<ref_ptr<Layer>>::reverse_iterator       rbegin()       { return _layers.rbegin(); }
    std::vector<ref_ptr<Layer>>::reverse_iterator       rend()         { return _layers.rend(); }
    
    std::vector<ref_ptr<Layer>>::const_iterator         begin()  const { return _layers.begin(); }
    std::vector<ref_ptr<Layer>>::const_iterator         end()    const { return _layers.end(); }
    std::vector<ref_ptr<Layer>>::const_reverse_iterator rbegin() const { return _layers.rbegin(); }
    std::vector<ref_ptr<Layer>>::const_reverse_iterator rend()   const { return _layers.rend(); }

    template< typename T >
    requires std::derived_from< T, Layer > 
    void PushLayer( ref_ptr<T>&& layer )
    {
        _layers.emplace_back( layer );
        layer->OnAttach();
    }

    template< typename T >
    requires std::derived_from< T, Layer >
    void PopLayer( T* type )
    {
        auto it = std::find_if( _layers.begin(), _layers.end(), []( const ref_ptr<T>& layer )
        {
            return typeid(T) == typeid(layer.get());
        } );
        if( it == _layers.end() ) return;
        else
        {
            it->get()->OnDetach();
            _layers.erase( it );
        }
    }

    template< typename T >
    requires std::derived_from< T, Layer >
    void PopLayer( const ref_ptr<T>& layer )
    {
        auto it = std::find( _layers.begin(), _layers.end(), layer );
        if( it == _layers.end() ) return;
        else
        {
            it->get()->OnDetach();
            _layers.erase( it );
        }
    }

    template< typename T >
    requires std::derived_from< T, Layer >
    ref_ptr<T> get()
    {
        auto it = std::find_if( _layers.begin(), _layers.end(), []( const ref_ptr<T>& layer ){ return typeid(T) == typeid(layer.get()); } );
        if( it == _layers.end() ) return {};
        else return _layers.at( it );
    }

protected:
    std::vector<ref_ptr<Layer>> _layers;
};

} // namespace AEON