#pragma once

class VertexArray;

class Renderer
{
public:
    static void Clear();
    static void Draw(VertexArray* vao, unsigned int indexCount);
};