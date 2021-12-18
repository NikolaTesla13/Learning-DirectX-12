#include "Window.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
{
    LRESULT result = 0;
    switch (msg)
    {
    case WM_KEYDOWN:
    {
        if (wparam == VK_ESCAPE)
            DestroyWindow(hwnd);
        break;
    }
    case WM_DESTROY:
    {
        PostQuitMessage(0);
        break;
    }
    case WM_SIZE:
    {
        Program::Window::m_DidResize = true;
        break;
    }
    default:
        result = DefWindowProcW(hwnd, msg, wparam, lparam);
    }
    return result;
}

namespace Program
{

    bool Window::m_DidResize;

    Window::Window(const WindowProps& windowProps)
    {
        m_WindowClass.cbSize = sizeof(WNDCLASSEXW);
        m_WindowClass.style = CS_HREDRAW | CS_VREDRAW;
        m_WindowClass.lpfnWndProc = (WNDPROC)WndProc;
        m_WindowClass.hInstance = windowProps.instance;
        m_WindowClass.hIcon = LoadIconW(0, IDI_APPLICATION);
        m_WindowClass.hCursor = LoadCursorW(0, IDC_ARROW);
        m_WindowClass.lpszClassName = L"WindowClass";
        m_WindowClass.hIconSm = LoadIconW(0, IDI_APPLICATION);

        if (!RegisterClassExW(&m_WindowClass))
        {
            MessageBoxA(0, "RegisterClassEx failed", "Fatal Error", MB_OK);
            PostQuitMessage(GetLastError());
        }

        m_WindowRect = { 0, 0, windowProps.width, windowProps.height };
        AdjustWindowRectEx(&m_WindowRect, WS_OVERLAPPEDWINDOW, FALSE, WS_EX_OVERLAPPEDWINDOW);
        LONG initialWidth = m_WindowRect.right - m_WindowRect.left;
        LONG initialHeight = m_WindowRect.bottom - m_WindowRect.top;

        m_WindowHandle = CreateWindowExW(WS_EX_OVERLAPPEDWINDOW, m_WindowClass.lpszClassName, windowProps.title, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, initialWidth, initialHeight, 0, 0, windowProps.instance, 0);

        if (!m_WindowHandle)
        {
            MessageBoxA(0, "CreateWindowEx failed", "Fatal Error", MB_OK);
            PostQuitMessage(GetLastError());
        }
    }

    bool Window::ShouldClose()
    {
        return m_ShouldClose;
    }

    void Window::Quit()
    {
        PostQuitMessage(0);
    }

    void Window::BeginFrame()
    {
        MSG msg = {};
        while (PeekMessageW(&msg, 0, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
                m_ShouldClose = true;
            TranslateMessage(&msg);
            DispatchMessageW(&msg);
        }
    }

    void Window::EndFrame()
    {
        // ¯\_(ツ)_/¯
    }

    WindowSize Window::getWindowSize()
    {
        if (GetClientRect(m_WindowHandle, &m_WindowRect))
        {
            WindowSize windowSize;
            windowSize.height = m_WindowRect.right - m_WindowRect.left;
            windowSize.width = m_WindowRect.bottom - m_WindowRect.top;
            return windowSize;
        }
        PostQuitMessage(GetLastError());
        return { 0, 0 };
    }

    HWND Window::getWindowHandle()
    {
        return m_WindowHandle;
    }
}