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