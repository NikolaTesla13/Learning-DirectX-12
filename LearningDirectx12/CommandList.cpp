#include "CommandAllocator.h"
#include "PipelineState.h"
#include "CommandList.h"

namespace Program::DX12
{
	CommandList::CommandList(const Device& device, const CommandAllocator& commandAllocator, const PipelineState& pipelineState)
	{
		device.CreateCommandList(m_CommandList, commandAllocator.GetRaw(), pipelineState.GetRaw());

		m_CommandList->Close();
	}

	CommandList::~CommandList()
	{
	}
}
