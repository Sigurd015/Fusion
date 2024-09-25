#include "Renderer.h"
#include "RendererContext.h"

namespace Fusion
{
	static RendererConfig s_Config;

	struct RendererData
	{
		Scope<RendererContext> Context;
	};
	static RendererData* s_Data = nullptr;

	void Renderer::Init(void* handle, uint32_t* width, uint32_t* height, bool vsync)
	{
		s_Data = new RendererData();

		s_Data->Context = RendererContext::Create(handle, width, height, vsync);
	}

	void Renderer::Shutdown()
	{
		delete s_Data;
	}

	void Renderer::OnWindowResize(uint32_t width, uint32_t height)
	{
	}

	const RendererConfig& Renderer::GetConfig()
	{
		return s_Config;
	}

	void Renderer::SetConfig(const RendererConfig& config)
	{
		s_Config = config;
	}
}