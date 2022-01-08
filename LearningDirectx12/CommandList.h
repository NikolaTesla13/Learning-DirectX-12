#pragma once

#include "System.h"
#include "Device.h"

namespace Program::DX12
{
	class CommandList
	{
	public:
		CommandList(const Device& device, const CommandAllocator& commandAllocator, const PipelineState& pipelineState);
		~CommandList();

	private:
		ComPtr<ID3D12GraphicsCommandList> m_CommandList;
	};
}