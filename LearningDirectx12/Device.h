#pragma once

#include "System.h"

namespace Program::DX12
{
	class Device
	{
	public:
		Device();
		~Device();

		void CreateCommandQueue(D3D12_COMMAND_QUEUE_DESC* desc, ComPtr<ID3D12CommandQueue>& commandQueue) const;
		void CreateCommandAllocator(ComPtr<ID3D12CommandAllocator>& commandAllocator) const;
		void CreateFence(ComPtr<ID3D12Fence>& fence) const;
		void CreateSwapchain(ComPtr<ID3D12CommandQueue> commandQueue, HWND hWnd, DXGI_SWAP_CHAIN_DESC1* desc, ComPtr<IDXGISwapChain1>& swapchain) const;
		void CreateDescriptorHeap(ComPtr<ID3D12DescriptorHeap>& descriptorHeap, D3D12_DESCRIPTOR_HEAP_DESC* desc) const;
		void CreateRenderTargetViews(ComPtr<ID3D12Resource>& resource, CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle) const;
		void CreateRootSignature(ComPtr<ID3D12RootSignature>& rootSignature, ComPtr<ID3DBlob> signature) const;

	private:
		void CreateFactory();
		void CreateAdapter();
		void CreateDevice();

		ComPtr<IDXGIFactory4> m_Factory;
		ComPtr<ID3D12Debug1> m_DebugController;
		ComPtr<IDXGIAdapter1> m_Adapter;
		ComPtr<ID3D12Device> m_Device;
		ComPtr<ID3D12DebugDevice> m_DebugDevice;
	};
}