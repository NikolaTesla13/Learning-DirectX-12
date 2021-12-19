#pragma once

#include "System.h"
#include "Device.h"

namespace Program::DX12
{
	class CommandQueue
	{
	public:
		CommandQueue(const Device& device);

	private:
		ID3D12CommandQueue* m_CommandQueue;
	};
}