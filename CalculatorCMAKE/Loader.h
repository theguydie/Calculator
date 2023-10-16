#pragma once

#include <Windows.h>
#include <string>
#include <functional>
#include <stdexcept>
#include <filesystem>

namespace fs = std::filesystem;

class Loader
{
public:
    Loader() : libraryHandle{ nullptr } {}

    ~Loader()
    {
        if (libraryHandle)
        {
            FreeLibrary(libraryHandle);
        }
    }

    void* tryLoadFunc(std::string libraryPath, std::string functionName)
    {
        libraryHandle = LoadLibrary(libraryPath.data());
        if (!libraryHandle)
        {
            void* symbol = GetProcAddress(libraryHandle, functionName.data());
            if (symbol)
            {
                return symbol;
            }
        }

        return nullptr;
    }

    template <typename FuncType>
    std::function<FuncType> loadFunction(std::string functionName)
    {
        for (const auto& dirEntry : fs::recursive_directory_iterator(fs::current_path()))
        {
            if (dirEntry.is_regular_file())
            {
                if (dirEntry.path().extension() == ".dll")
                {
                    auto path = dirEntry.path().filename().string();
                    auto symbol = tryLoadFunc(path, functionName);
                    if (symbol)
                    {
                        return std::function<FuncType>(reinterpret_cast<FuncType*>(symbol));
                    }
                }
            }
        }

        throw std::runtime_error("Error: library with function '" + std::string(functionName) + "' not found");
    }

private:
    HMODULE libraryHandle;
};
