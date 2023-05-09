#pragma once

#include <Base/Base.h>

#include "../Event.h"

namespace AEON
{

class ApplicationEvent : public Event
{

};

class ApplicationCloseEvent : public ApplicationEvent
{
    
};

} // namespace AEON
