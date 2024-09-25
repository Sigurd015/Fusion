#pragma once
#include "RendererConfig.h"

namespace Fusion
{
	class Renderer
	{
	public:
		// Handle can be window handle(Win32) or view handle(MacOS)
		static void Init(void* handle, uint32_t* width, uint32_t* height, bool vsync);
		static void Shutdown();

		static void OnWindowResize(uint32_t width, uint32_t height);

		static const RendererConfig& GetConfig();
		static void SetConfig(const RendererConfig& config);

		static RendererAPIType GetAPI() { return GetConfig().APIType; }
	};
}
