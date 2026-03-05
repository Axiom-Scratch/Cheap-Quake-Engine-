#include "Renderer/Buffers/VertexArray.h"
#include "Renderer/OpenGL/GLVertexArray.h"

VertexArray* VertexArray::Create()
{
    return new GLVertexArray();
}