#include "Framework.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    LoggerProps loggerProps;
    loggerProps.identificator = "Program";
    loggerProps.onlyDebug = true;
    loggerProps.shodID = true;
    loggerProps.showTime = true;
    Logger logger(loggerProps);
    
    WindowProps windowProps;
    windowProps.height = 720;
    windowProps.width = 1080;
    windowProps.title = L"Learning DirectX 12";
    windowProps.instance = hInstance;
    Window window(windowProps);

    const DX12::Vertex triangleVertices[] =
    {
        { { 0.0f, 0.25f * 1080 / 720, 0.0f }, { 1.0f, 0.0f, 0.0f, 1.0f } },
        { { 0.25f, -0.25f * 1080 / 720, 0.0f }, { 0.0f, 1.0f, 0.0f, 1.0f } },
        { { -0.25f, -0.25f * 1080 / 720, 0.0f }, { 0.0f, 0.0f, 1.0f, 1.0f } }
    };

    DX12::Device device;
    DX12::CommandQueue commandQueue(device);
    DX12::CommandAllocator commandAllocator(device);
    DX12::Fence fence(device);
    DX12::Swapchain swapchain(device, window, commandQueue);
    DX12::RenderTargetViews renderTargetView(device, swapchain);
    DX12::RootSignature rootSignature(device);
    DX12::PipelineState pipelineState(device, rootSignature, L"shader.hlsl");
    DX12::CommandList commandList(device, commandAllocator, pipelineState);
    DX12::VertexBuffer vertexBuffer(device, triangleVertices);

    while (!window.ShouldClose())
    {
        TIME("New frame");
        window.BeginFrame();

        window.Quit();
        window.EndFrame();
    }

    return 0;
}