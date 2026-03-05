#include "Renderer/Shader/Shader.h"

#include "Renderer/OpenGL/GLShader.h"

Shader* Shader::Create(const std::string& vertexSource, const std::string& fragmentSource)
{
    return new GLShader(vertexSource, fragmentSource);
}
