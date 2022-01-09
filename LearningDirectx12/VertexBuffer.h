#pragma once

#include "System.h"
#include "Device.h"

namespace Program::DX12
{
	struct Vertex
	{
		XMFLOAT3 position;
		XMFLOAT4 color;
	};

	class VertexBuffer
	{
	public:
		VertexBuffer(const Device& device, const Vertex vertices[]);
		~VertexBuffer();

	private:
		const float m_aspectRatio = 1080 / 720;
		ComPtr<ID3D12Resource> m_vertexBuffer;
		D3D12_VERTEX_BUFFER_VIEW m_vertexBufferView;
	};
}
