#pragma once
#include <cstdint>

namespace Fusion
{
	enum class RendererAPIType
	{
		None = 0,
		Vulkan = 1,
		DX12 = 2,
		Metal = 3,
	};

	struct RendererConfig
	{
		RendererAPIType APIType;

		void* WindowHandle;
		uint32_t Width, Height;
		bool VSync;
	};
}