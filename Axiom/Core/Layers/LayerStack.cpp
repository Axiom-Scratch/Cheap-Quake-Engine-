#include "LayerStack.h"

#include <algorithm>

LayerStack::LayerStack() = default;

LayerStack::~LayerStack()
{
    for (Layer* layer : m_Layers)
    {
        if (layer)
        {
            layer->OnDetach();
            delete layer;
        }
    }

    m_Layers.clear();
    m_LayerInsertIndex = 0;
}

void LayerStack::PushLayer(Layer* layer)
{
    if (!layer)
    {
        return;
    }

    m_Layers.emplace(
        m_Layers.begin()
            + static_cast<std::vector<Layer*>::difference_type>(m_LayerInsertIndex),
        layer);
    ++m_LayerInsertIndex;
    layer->OnAttach();
}

void LayerStack::PushOverlay(Layer* overlay)
{
    if (!overlay)
    {
        return;
    }

    m_Layers.emplace_back(overlay);
    overlay->OnAttach();
}

void LayerStack::PopLayer(Layer* layer)
{
    if (!layer)
    {
        return;
    }

    const auto end = m_Layers.begin()
        + static_cast<std::vector<Layer*>::difference_type>(m_LayerInsertIndex);
    auto it = std::find(m_Layers.begin(), end, layer);
    if (it == end)
    {
        return;
    }

    (*it)->OnDetach();
    delete *it;
    m_Layers.erase(it);
    --m_LayerInsertIndex;
}

void LayerStack::PopOverlay(Layer* overlay)
{
    if (!overlay)
    {
        return;
    }

    auto it = std::find(
        m_Layers.begin()
            + static_cast<std::vector<Layer*>::difference_type>(m_LayerInsertIndex),
        m_Layers.end(),
        overlay);
    if (it == m_Layers.end())
    {
        return;
    }

    (*it)->OnDetach();
    delete *it;
    m_Layers.erase(it);
}

std::vector<Layer*>::iterator LayerStack::begin()
{
    return m_Layers.begin();
}

std::vector<Layer*>::iterator LayerStack::end()
{
    return m_Layers.end();
}

std::vector<Layer*>::const_iterator LayerStack::begin() const
{
    return m_Layers.begin();
}

std::vector<Layer*>::const_iterator LayerStack::end() const
{
    return m_Layers.end();
}
