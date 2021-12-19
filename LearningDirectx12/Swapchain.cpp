#include "Swapchain.h"

namespace Program::DX12
{
	Swapchain::Swapchain(const Device& device, const Window& window, CommandQueue& commandQueue)
	{
		DXGI_SWAP_CHAIN_DESC1 swapchainDescription = {};
		swapchainDescription.BufferCount = 2;
		swapchainDescription.Width = window.GetWindowSize().width;
		swapchainDescription.Height = window.GetWindowSize().height;
		swapchainDescription.Format = DXGI_FORMAT_R8G8B8A8_UNORM;
		swapchainDescription.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		swapchainDescription.SwapEffect = DXGI_SWAP_EFFECT_FLIP_DISCARD;
		swapchainDescription.SampleDesc.Count = 1;

		device.CreateSwapchain(commandQueue.GetCommandQueue(), window.GetWindowHandle(), &swapchainDescription, m_Swapchain);
	}

	Swapchain::~Swapchain()
	{

	}

	void Swapchain::GetBuffer(UINT index, ComPtr<ID3D12Resource>& renderTarget) const
	{
		ThrowIfFailed(m_Swapchain->GetBuffer(index, IID_PPV_ARGS(renderTarget.ReleaseAndGetAddressOf())));
	}
}
