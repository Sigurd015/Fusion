#pragma once
#include "RendererConfig.h"

#include <cstdint>

namespace Fusion
{
	class RendererContext
	{
	public:
		virtual void SwapBuffer(bool VSync) = 0;
		static Scope<RendererContext> Create(void *window, uint32_t width, uint32_t height, bool vsync);
	};
}