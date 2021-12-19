#include "CommandAllocator.h"

namespace Program::DX12
{
	CommandAllocator::CommandAllocator(const Device& device)
	{
		device.CreateCommandAllocator(m_CommandAllocator);
	}

	CommandAllocator::~CommandAllocator()
	{
	}
}

