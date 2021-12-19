#include "CommandQueue.h"

namespace Program::DX12
{
	CommandQueue::CommandQueue(const Device& device)
	{
		D3D12_COMMAND_QUEUE_DESC queueDesc = {};
		queueDesc.Flags = D3D12_COMMAND_QUEUE_FLAG_NONE;
		queueDesc.Type = D3D12_COMMAND_LIST_TYPE_DIRECT;

		device.CreateCommandQueue(&queueDesc, m_CommandQueue);
	}
}

