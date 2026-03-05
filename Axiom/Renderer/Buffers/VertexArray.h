#pragma once

class VertexBuffer;
class IndexBuffer;

class VertexArray
{
public:
    virtual ~VertexArray() = default;

    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;

    virtual void AddVertexBuffer(VertexBuffer* buffer) = 0;
    virtual void SetIndexBuffer(IndexBuffer* buffer) = 0;

    static VertexArray* Create();
};