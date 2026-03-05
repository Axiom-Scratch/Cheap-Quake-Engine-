#include "GLVertexArray.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Renderer/Buffers/IndexBuffer.h"
#include "Renderer/Buffers/VertexBuffer.h"

GLVertexArray::GLVertexArray()
{
    glGenVertexArrays(1, &m_RendererID);
}

GLVertexArray::~GLVertexArray()
{
    glDeleteVertexArrays(1, &m_RendererID);
}

void GLVertexArray::Bind() const
{
    glBindVertexArray(m_RendererID);
}

void GLVertexArray::Unbind() const
{
    glBindVertexArray(0);
}

void GLVertexArray::AddVertexBuffer(VertexBuffer* buffer)
{
    Bind();
    buffer->Bind();
}

void GLVertexArray::SetIndexBuffer(IndexBuffer* buffer)
{
    Bind();
    buffer->Bind();
}
