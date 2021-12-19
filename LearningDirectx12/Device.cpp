#include "Device.h"

namespace Program::DX12
{
	Device::Device()
	{
		CreateFactory();
		CreateAdapter();
		CreateDevice();
	}

	void Device::CreateCommandQueue(D3D12_COMMAND_QUEUE_DESC* desc, ID3D12CommandQueue* commandQueue) const
	{
		ThrowIfFailed(m_Device->CreateCommandQueue(desc, IID_PPV_ARGS(&commandQueue)));
	}

	void Device::CreateFactory()
	{
		UINT dxgiFactoryFlags = 0;

#ifdef _DEBUG
		ID3D12Debug* dc;
		ThrowIfFailed(D3D12GetDebugInterface(IID_PPV_ARGS(&dc)));
		ThrowIfFailed(dc->QueryInterface(IID_PPV_ARGS(&m_DebugController)));
		m_DebugController->EnableDebugLayer();
		m_DebugController->SetEnableGPUBasedValidation(true);

		dxgiFactoryFlags |= DXGI_CREATE_FACTORY_DEBUG;

		dc->Release();
#endif
		ThrowIfFailed(CreateDXGIFactory2(dxgiFactoryFlags, IID_PPV_ARGS(&m_Factory)));
	}

	void Device::CreateAdapter()
	{
		for (UINT adapterIndex = 0; DXGI_ERROR_NOT_FOUND != m_Factory->EnumAdapters1(adapterIndex, &m_Adapter); adapterIndex++)
		{
			DXGI_ADAPTER_DESC1 desc;
			m_Adapter->GetDesc1(&desc);

			if (desc.Flags & DXGI_ADAPTER_FLAG_SOFTWARE)
			{
				continue;
			}

			if (SUCCEEDED(D3D12CreateDevice(m_Adapter, D3D_FEATURE_LEVEL_12_0, _uuidof(ID3D12Device), nullptr)))
			{
				break;
			}

			m_Adapter->Release();
		}
	}

	void Device::CreateDevice()
	{
		ThrowIfFailed(D3D12CreateDevice(m_Adapter, D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&m_Device)));
#ifdef _DEBUG
		ThrowIfFailed(m_Device->QueryInterface(&m_DebugDevice));
#endif
	}
}