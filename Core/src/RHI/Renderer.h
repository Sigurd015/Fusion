#pragma once
#include "RendererConfig.h"

namespace Fusion
{
	class Renderer
	{
	public:
		static void Init(const RendererConfig& config);
		static void Shutdown();

		static void OnWindowResize(uint32_t width, uint32_t height);

		static const RendererConfig& GetConfig();
		static RendererAPIType GetAPI() { return GetConfig().APIType; }
	};
}
