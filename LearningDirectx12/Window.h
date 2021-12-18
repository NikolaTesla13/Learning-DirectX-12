#pragma once

#include "System.h"

LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);

namespace Program
{
	struct WindowProps
	{
		HINSTANCE instance;
		LONG width, height;
		LPCWSTR title;
	};

	struct WindowSize
	{
		UINT width, height;
	};

	class Window
	{
	public:
		Window(const WindowProps& windowProps);

		bool ShouldClose();
		void BeginFrame();
		void EndFrame();
		void Quit();

		WindowSize getWindowSize();
		HWND getWindowHandle();

		static bool m_DidResize;

	private:
		HWND m_WindowHandle;
		WNDCLASSEXW m_WindowClass;
		RECT m_WindowRect;
		bool m_ShouldClose = false;
	};
}
