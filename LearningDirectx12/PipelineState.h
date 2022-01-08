#pragma once

#include "System.h"
#include "Device.h"
#include "RootSignature.h"

namespace Program::DX12
{
	class PipelineState
	{
	public:
		PipelineState(const Device& device, RootSignature rootSignature, const std::wstring& shaderPath);
		~PipelineState();

	private:
		ComPtr<ID3DBlob> m_VertexShader;
		ComPtr<ID3DBlob> m_PixelShader;
		ComPtr<ID3D12PipelineState> m_pipelineState;
	};
}