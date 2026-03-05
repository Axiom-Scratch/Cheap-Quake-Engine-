#include "Renderer.h"

#include "Buffers/VertexArray.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

void Renderer::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Renderer::Draw(VertexArray* vao, unsigned int indexCount)
{
    vao->Bind();
    glDrawElements(GL_TRIANGLES, indexCount, GL_UNSIGNED_INT, nullptr);
}
