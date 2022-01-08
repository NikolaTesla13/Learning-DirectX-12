#pragma once

#include "System.h"
#include "Device.h"

namespace Program::DX12
{
	class RootSignature
	{
	public:
		RootSignature(const Device& device);
		~RootSignature();

		ComPtr<ID3D12RootSignature> GetRawRootSignature() { return m_rootSignature; }

	private:
		ComPtr<ID3D12RootSignature> m_rootSignature;
	};
}