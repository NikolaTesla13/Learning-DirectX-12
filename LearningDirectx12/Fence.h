#pragma once

#include "System.h"
#include "Device.h"

namespace Program::DX12
{
	class Fence
	{
	public:
		Fence(const Device& device);
		~Fence();

	private:
		UINT m_FrameIndex;
		HANDLE m_FenceEvent;
		ComPtr<ID3D12Fence> m_Fence;
		UINT64 m_FenceValue;
	};
}