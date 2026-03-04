#pragma once

#include "Base.h"

#include <filesystem>
#include <fstream>
#include <string>

class FileSystem
{
public:
    static bool Exists(const std::filesystem::path& path)
    {
        return std::filesystem::exists(path);
    }

    static std::string ReadFile(const std::filesystem::path& path)
    {
        std::ifstream file(path, std::ios::binary);
        if (!file)
        {
            return {};
        }

        std::string data;
        file.seekg(0, std::ios::end);
        data.resize(static_cast<size_t>(file.tellg()));
        file.seekg(0, std::ios::beg);
        file.read(data.data(), static_cast<std::streamsize>(data.size()));
        return data;
    }

    static bool WriteFile(const std::filesystem::path& path, const std::string& data)
    {
        std::ofstream file(path, std::ios::binary);
        if (!file)
        {
            return false;
        }

        file.write(data.data(), static_cast<std::streamsize>(data.size()));
        return file.good();
    }

    static std::filesystem::path GetWorkingDirectory()
    {
        return std::filesystem::current_path();
    }
};
