#include "GLShader.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

GLShader::GLShader(const std::string& vertexSource, const std::string& fragmentSource)
{
    const unsigned int vertex = CompileStage(GL_VERTEX_SHADER, vertexSource);
    const unsigned int fragment = CompileStage(GL_FRAGMENT_SHADER, fragmentSource);

    m_RendererID = glCreateProgram();
    glAttachShader(m_RendererID, vertex);
    glAttachShader(m_RendererID, fragment);
    glLinkProgram(m_RendererID);
    glValidateProgram(m_RendererID);

    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

GLShader::~GLShader()
{
    if (m_RendererID != 0U)
    {
        glDeleteProgram(m_RendererID);
    }
}

void GLShader::Bind() const
{
    glUseProgram(m_RendererID);
}

void GLShader::Unbind() const
{
    glUseProgram(0);
}

unsigned int GLShader::CompileStage(unsigned int type, const std::string& source)
{
    const unsigned int shader = glCreateShader(type);
    const char* sourceCStr = source.c_str();
    glShaderSource(shader, 1, &sourceCStr, nullptr);
    glCompileShader(shader);
    return shader;
}
