#pragma once

#include "Renderer/Buffers/VertexBuffer.h"

class GLVertexBuffer : public VertexBuffer
{
public:
    GLVertexBuffer(const void* data, std::uint32_t size);
    ~GLVertexBuffer();

    void Bind() const override;
    void Unbind() const override;

private:
    unsigned int m_RendererID;
};