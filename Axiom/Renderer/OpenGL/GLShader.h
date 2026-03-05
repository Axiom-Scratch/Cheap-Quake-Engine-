#pragma once

#include "Renderer/Shader/Shader.h"

#include <string>

class GLShader : public Shader
{
public:
    GLShader(const std::string& vertexSource, const std::string& fragmentSource);
    ~GLShader() override;

    void Bind() const override;
    void Unbind() const override;

private:
    static unsigned int CompileStage(unsigned int type, const std::string& source);

    unsigned int m_RendererID = 0;
};
