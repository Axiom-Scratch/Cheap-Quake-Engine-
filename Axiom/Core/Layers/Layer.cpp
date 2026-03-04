#include "Layer.h"

#include <utility>

Layer::Layer(std::string name)
    : m_DebugName(std::move(name))
{
}
