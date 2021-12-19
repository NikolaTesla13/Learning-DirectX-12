#pragma once

#include "System.h"
#include "Window.h"
#include "Device.h"
#include "CommandQueue.h"

namespace Program::DX12
{
	struct SwapchainProps
	{
		Device device;
		Window window;
		CommandQueue commandQueue;
	};

	class Swapchain
	{
	public:
		Swapchain(const Device& device, const Window& window, CommandQueue& commandQueue);
		~Swapchain();

		void GetBuffer(UINT index, ComPtr<ID3D12Resource>& renderTarget) const;

	private:
		ComPtr<IDXGISwapChain1> m_Swapchain;
	};
}