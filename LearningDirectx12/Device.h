#pragma once

#include "System.h"

namespace Program::DX12
{
	class Device
	{
	public:
		Device();
		~Device() {};

		IDXGIFactory4* GetFactory();
		ID3D12DebugDevice* GetDebugDevice();
		IDXGIAdapter1* GetAdapter();
		ID3D12Device* GetDevice();
		DXGI_ADAPTER_DESC1 GetAdapterDescription();

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