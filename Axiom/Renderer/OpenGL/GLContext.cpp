#include "GLContext.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

bool GLContext::Init(GLFWwindow* window)
{
    if (window == nullptr)
    {
        return false;
    }

    if (!gladLoadGLLoader(reinterpret_cast<GLADloadproc>(glfwGetProcAddress)))
    {
        return false;
    }

    glEnable(GL_DEPTH_TEST);
    return true;
}
