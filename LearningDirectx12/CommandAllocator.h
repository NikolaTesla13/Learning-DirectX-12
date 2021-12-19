#pragma once

#include "System.h"
#include "Device.h"

namespace Program::DX12
{
	class CommandAllocator
	{
	public:
		CommandAllocator(const Device& device);
		~CommandAllocator();

	private:
		ComPtr<ID3D12CommandAllocator> m_CommandAllocator;
	};
}