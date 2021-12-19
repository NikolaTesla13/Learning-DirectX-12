#pragma once
#pragma once

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#define _CRT_SECURE_NO_WARNINGS

#include <windows.h>
#include <errhandlingapi.h>
#include <wrl.h>
#include <strsafe.h>
#include <atlbase.h>
#include <atlconv.h>
#include "d3dx12.h"
#include <dxgi1_6.h>
#include <D3Dcompiler.h>
#include <DirectXMath.h>
#include <wrl/client.h>
#include <wrl.h>
#include <shellapi.h>

#include <cassert>
#include <string>
#include <memory>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <sstream>

#include "Logger.h"
#include "Timer.h"

#define CONCAT_(x,y) x##y
#define CONCAT(x,y) CONCAT_(x,y)
#define TIME(x) Timer CONCAT(timer, __LINE__)(x)

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
