#include "Renderer/Buffers/VertexBuffer.h"
#include "Renderer/OpenGL/GLVertexBuffer.h"

VertexBuffer* VertexBuffer::Create(const void* data, std::uint32_t size)
{
    return new GLVertexBuffer(data, size);
}