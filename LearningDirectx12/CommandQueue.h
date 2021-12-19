#pragma once

#include "Device.h"
#include "System.h"

namespace Program::DX12
{
	class CommandQueue
	{
	public:
		CommandQueue(const Device& device);
		~CommandQueue();

		ComPtr<ID3D12CommandQueue> GetCommandQueue() { return m_CommandQueue;  }

	private:
		ComPtr<ID3D12CommandQueue> m_CommandQueue;
	};
}