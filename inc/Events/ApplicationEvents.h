#pragma once

#include <Base/Base.h>
#include <Base/Event.h>

namespace aer
{

class ApplicationEvent : public Event
{

};

class ApplicationCloseEvent : public ApplicationEvent
{
    
};

} // namespace aer
