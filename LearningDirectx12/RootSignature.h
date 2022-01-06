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

	private:
		ComPtr<ID3D12RootSignature> m_rootSignature;
	};
}