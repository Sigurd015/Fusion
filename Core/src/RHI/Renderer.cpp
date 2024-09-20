#include "Renderer.h"
#include "RendererContext.h"

namespace Fusion
{
	static RendererConfig s_Config;

	struct RendererData
	{
		Scope<RendererContext> Context;
	};

	static RendererData *s_Data = nullptr;

	void Renderer::Init(const RendererConfig &config)
	{
		s_Config = config;
		s_Data = new RendererData();

		s_Data->Context = RendererContext::Create(config.WindowHandle, config.Width, config.Height, config.VSync);
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
}