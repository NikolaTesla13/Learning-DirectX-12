#include "RenderTargetViews.h"

namespace Program::DX12
{
	RenderTargetViews::RenderTargetViews(const Device& device, const Swapchain& swapchain)
	{
		D3D12_DESCRIPTOR_HEAP_DESC rtvHeapDesc = {};
		rtvHeapDesc.NumDescriptors = 2;
		rtvHeapDesc.Type = D3D12_DESCRIPTOR_HEAP_TYPE_RTV;
		rtvHeapDesc.Flags = D3D12_DESCRIPTOR_HEAP_FLAG_NONE;

		device.CreateDescriptorHeap(m_rtvHeap, &rtvHeapDesc);

		CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle(m_rtvHeap->GetCPUDescriptorHandleForHeapStart());

		for (UINT n = 0; n < 2; n++)
		{
			swapchain.GetBuffer(0, m_renderTargets[n]);
			device.CreateRenderTargetViews(m_renderTargets[n], rtvHandle);
			rtvHandle.Offset(1, m_rtvDescriptorSize);
		}
	}

	RenderTargetViews::~RenderTargetViews()
	{
	}
}

