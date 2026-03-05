#pragma once

#include <cstdint>

class IndexBuffer
{
public:
    virtual ~IndexBuffer() = default;

    virtual void Bind() const = 0;
    virtual void Unbind() const = 0;

    virtual std::uint32_t GetCount() const = 0;

    static IndexBuffer* Create(const std::uint32_t* indices, std::uint32_t count);
};