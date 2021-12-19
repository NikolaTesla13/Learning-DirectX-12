#include "Fence.h"

namespace Program::DX12
{
	Fence::Fence(const Device& device)
	{
		device.CreateFence(m_Fence);
	}
}
