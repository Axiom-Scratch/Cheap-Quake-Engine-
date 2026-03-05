#pragma once

#include "Renderer/Buffers/VertexArray.h"

class GLVertexArray : public VertexArray
{
public:
    GLVertexArray();
    ~GLVertexArray();

    void Bind() const override;
    void Unbind() const override;

    void AddVertexBuffer(VertexBuffer* buffer) override;
    void SetIndexBuffer(IndexBuffer* buffer) override;

private:
    unsigned int m_RendererID;
};