#include "Renderer.h"
#include "RendererContext.h"

namespace Fusion
{
	struct RendererData
	{
		RendererConfig s_Config;
		Scope<RendererContext> Context;
	};

	static RendererData* s_Data = nullptr;

	void Renderer::Init(const RendererConfig& config)
	{
		s_Data = new RendererData();
		s_Data->s_Config = config;

		s_Data->Context = RendererContext::Create(s_Data->s_Config.WindowHandle, s_Data->s_Config.Width, s_Data->s_Config.Height, s_Data->s_Config.VSync);
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
		return s_Data->s_Config;
	}
}