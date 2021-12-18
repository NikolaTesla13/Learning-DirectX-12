#pragma once
#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define UNICODE
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <errhandlingapi.h>
#include <wrl.h>
#include <strsafe.h>
#include <atlbase.h>
#include <atlconv.h>
#include <d3d12.h>
#include <dxgi1_5.h>
#include <wrl/client.h>

#include <cassert>
#include <string>
#include <memory>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <sstream>

using Microsoft::WRL::ComPtr;

namespace Program::DX12
{
    class com_exception : public std::exception
    {
    public:
        com_exception(HRESULT hr) : result(hr) {}

        const char* what() const override
        {
            static char s_str[64] = {};
            sprintf_s(s_str, "Failure with HRESULT of %08X",
                static_cast<unsigned int>(result));
            return s_str;
        }

    private:
        HRESULT result;
    };

    inline void ThrowIfFailed(HRESULT hr)
    {
        if (FAILED(hr))
        {
            throw com_exception(hr);
        }
    }

}
