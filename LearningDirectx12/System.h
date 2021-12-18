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

#include <cassert>
#include <string>
#include <memory>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <sstream>

#define CheckResult(hResult) if (FAILED(hResult)) { MessageBoxA(0, "Something failed", "Fatal Error", MB_OK); PostQuitMessage(GetLastError()); __debugbreak(); }

