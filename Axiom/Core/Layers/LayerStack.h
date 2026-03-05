#pragma once

#include "Layer.h"

#include <cstdint>
#include <vector>

class LayerStack
{
public:
    AXIOM_API LayerStack();
    AXIOM_API ~LayerStack();

    AXIOM_API void PushLayer(Layer* layer);
    AXIOM_API void PushOverlay(Layer* overlay);

    AXIOM_API void PopLayer(Layer* layer);
    AXIOM_API void PopOverlay(Layer* overlay);

    AXIOM_API std::vector<Layer*>::iterator begin();
    AXIOM_API std::vector<Layer*>::iterator end();
    AXIOM_API std::vector<Layer*>::const_iterator begin() const;
    AXIOM_API std::vector<Layer*>::const_iterator end() const;

private:
    std::vector<Layer*> m_Layers;
    std::uint32_t m_LayerInsertIndex = 0;
};
