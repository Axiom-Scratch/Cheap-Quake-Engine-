#pragma once

#include "Renderer/Buffers/IndexBuffer.h"

class GLIndexBuffer : public IndexBuffer
{
public:
    GLIndexBuffer(const std::uint32_t* indices, std::uint32_t count);
    ~GLIndexBuffer();

    void Bind() const override;
    void Unbind() const override;

    std::uint32_t GetCount() const override;

private:
    unsigned int m_RendererID;
    std::uint32_t m_Count;
};