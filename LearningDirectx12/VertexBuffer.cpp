#include "VertexBuffer.h"

namespace Program::DX12
{
	VertexBuffer::VertexBuffer(const Device& device, const Vertex vertices[])
	{
		const UINT vertexBufferSize = sizeof(vertices);
		device.CreateCommittedResource(m_vertexBuffer, vertexBufferSize);

		UINT8* pVertexDataBegin;
		CD3DX12_RANGE readRange(0, 0);
		ThrowIfFailed(m_vertexBuffer->Map(0, &readRange, reinterpret_cast<void**>(&pVertexDataBegin)));
		memcpy(pVertexDataBegin, vertices, sizeof(vertices));
		m_vertexBuffer->Unmap(0, nullptr);

		m_vertexBufferView.BufferLocation = m_vertexBuffer->GetGPUVirtualAddress();
		m_vertexBufferView.StrideInBytes = sizeof(Vertex);
		m_vertexBufferView.SizeInBytes = vertexBufferSize;
	} 

	VertexBuffer::~VertexBuffer()
	{

	}
}
