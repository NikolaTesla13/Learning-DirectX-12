#pragma once

#include "System.h"
#include "Device.h"

namespace Program::DX12
{
	class CommandAllocator
	{
	public:
		CommandAllocator(const Device& device);

	private:
		ID3D12CommandAllocator* m_CommandAllocator;
	};
}