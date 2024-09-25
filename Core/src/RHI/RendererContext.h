#pragma once
#include "RendererConfig.h"

namespace Fusion
{
	class RendererContext
	{
	public:
		static Scope<RendererContext> Create(void* handle, uint32_t* width, uint32_t* height, bool vsync);
	};
}