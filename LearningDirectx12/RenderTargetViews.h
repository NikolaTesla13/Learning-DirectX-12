#pragma once

#include "System.h"
#include "Swapchain.h"

namespace Program::DX12
{
	class RenderTargetViews
	{
	public:
		RenderTargetViews(const Device& device, const Swapchain& swapchain);
		~RenderTargetViews();

	private:
		ComPtr<ID3D12DescriptorHeap> m_rtvHeap;
		UINT m_rtvDescriptorSize;
		ComPtr<ID3D12Resource> m_renderTargets[2];
	};
}