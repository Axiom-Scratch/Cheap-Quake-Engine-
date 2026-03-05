#include "Renderer/Buffers/IndexBuffer.h"
#include "Renderer/OpenGL/GLIndexBuffer.h"

IndexBuffer* IndexBuffer::Create(const std::uint32_t* indices, std::uint32_t count)
{
    return new GLIndexBuffer(indices, count);
}