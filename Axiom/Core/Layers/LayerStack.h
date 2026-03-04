#pragma once

#include "Layer.h"

#include <cstdint>
#include <vector>

class LayerStack
{
public:
    LayerStack();
    ~LayerStack();

    void PushLayer(Layer* layer);
    void PushOverlay(Layer* overlay);

    void PopLayer(Layer* layer);
    void PopOverlay(Layer* overlay);

    std::vector<Layer*>::iterator begin();
    std::vector<Layer*>::iterator end();
    std::vector<Layer*>::const_iterator begin() const;
    std::vector<Layer*>::const_iterator end() const;

private:
    std::vector<Layer*> m_Layers;
    std::uint32_t m_LayerInsertIndex = 0;
};
