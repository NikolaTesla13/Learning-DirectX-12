#include "CommandQueue.h" 
#include "Device.h"


namespace Program::DX12
{
	Device::Device()
	{
		CreateFactory();
		CreateAdapter();
		CreateDevice();
	}

	Device::~Device()
	{
	}

	void Device::CreateCommandQueue(D3D12_COMMAND_QUEUE_DESC* desc, ComPtr<ID3D12CommandQueue>& commandQueue) const
	{
		ThrowIfFailed(m_Device->CreateCommandQueue(desc, IID_PPV_ARGS(commandQueue.GetAddressOf())));
	}

	void Device::CreateCommandAllocator(ComPtr<ID3D12CommandAllocator>& commandAllocator) const
	{
		ThrowIfFailed(m_Device->CreateCommandAllocator(D3D12_COMMAND_LIST_TYPE_DIRECT, IID_PPV_ARGS(commandAllocator.GetAddressOf())));
	}

	void Device::CreateFence(ComPtr<ID3D12Fence>& fence) const
	{
		ThrowIfFailed(m_Device->CreateFence(0, D3D12_FENCE_FLAG_NONE, IID_PPV_ARGS(fence.GetAddressOf())));
	}

	void Device::CreateSwapchain(ComPtr<ID3D12CommandQueue> commandQueue, HWND hWnd, DXGI_SWAP_CHAIN_DESC1* desc, ComPtr<IDXGISwapChain1>& swapchain) const
	{
		ThrowIfFailed(m_Factory->CreateSwapChainForHwnd(commandQueue.Get(), hWnd, desc, nullptr, nullptr, &swapchain));
		ThrowIfFailed(m_Factory->MakeWindowAssociation(hWnd, DXGI_MWA_NO_ALT_ENTER));
	}

	void Device::CreateDescriptorHeap(ComPtr<ID3D12DescriptorHeap>& descriptorHeap, D3D12_DESCRIPTOR_HEAP_DESC* desc) const
	{
		ThrowIfFailed(m_Device->CreateDescriptorHeap(desc, IID_PPV_ARGS(&descriptorHeap)));
	}

	void Device::CreateRenderTargetViews(ComPtr<ID3D12Resource>& resource, CD3DX12_CPU_DESCRIPTOR_HANDLE rtvHandle) const
	{
		m_Device->CreateRenderTargetView(resource.Get(), nullptr, rtvHandle);
	}

	void Device::CreateRootSignature(ComPtr<ID3D12RootSignature>& rootSignature, ComPtr<ID3DBlob> signature) const
	{
		ThrowIfFailed(m_Device->CreateRootSignature(0, signature->GetBufferPointer(), signature->GetBufferSize(), IID_PPV_ARGS(&rootSignature)));
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

			if (SUCCEEDED(D3D12CreateDevice(m_Adapter.Get(), D3D_FEATURE_LEVEL_12_0, _uuidof(ID3D12Device), nullptr)))
			{
				break;
			}

			m_Adapter->Release();
		}
	}

	void Device::CreateDevice()
	{
		ThrowIfFailed(D3D12CreateDevice(m_Adapter.Get(), D3D_FEATURE_LEVEL_12_0, IID_PPV_ARGS(&m_Device)));
#ifdef _DEBUG
		ThrowIfFailed(m_Device->QueryInterface(m_DebugDevice.ReleaseAndGetAddressOf()));
#endif
	}
}