#include "Renderer.h"
#include "RendererContext.h"

// Vulkan
#include "../Backend/Vulkan/VulkanContext.h"

namespace Fusion
{
	Scope<RendererContext> RendererContext::Create(void* handle, uint32_t* width, uint32_t* height, bool vsync)
	{
		switch (Renderer::GetAPI())
		{
		case Fusion::RendererAPIType::Vulkan:
			return CreateScope<VulkanContext>(handle, width, height, vsync);
		}

		FUSION_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}