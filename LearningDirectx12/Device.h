#pragma once

#include "System.h"

namespace Program::DX12
{
	class Device
	{
	public:
		Device();
		~Device() {};

		void CreateCommandQueue(D3D12_COMMAND_QUEUE_DESC* desc, ID3D12CommandQueue* commandQueue) const;

	private:
		void CreateFactory();
		void CreateAdapter();
		void CreateDevice();

		IDXGIFactory4* m_Factory;
		ID3D12Debug1* m_DebugController;
		IDXGIAdapter1* m_Adapter;
		ID3D12Device* m_Device;
		ID3D12DebugDevice* m_DebugDevice;
	};
}