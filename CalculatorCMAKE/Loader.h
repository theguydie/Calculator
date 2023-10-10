#pragma once

#include <windows.h>
#include <string>
#include <functional>
#include <stdexcept>

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

    template <typename FuncType>
    std::function<FuncType> loadFunction(const char* libraryPath, const char* functionName)
    {
        libraryHandle = LoadLibraryA(libraryPath);
        if (!libraryHandle)
        {
            DWORD error = GetLastError();
            throw std::runtime_error("Error loading library: " + std::to_string(error));
        }

        void* symbol = GetProcAddress(libraryHandle, functionName);
        if (!symbol)
        {
            DWORD error = GetLastError();
            throw std::runtime_error("Error loading symbol: " + std::to_string(error));
        }

        return std::function<FuncType>(reinterpret_cast<FuncType*>(symbol));
    }

private:
    HMODULE libraryHandle;
};
