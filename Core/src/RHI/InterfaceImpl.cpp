#include "Renderer.h"
#include "RendererContext.h"

// Vulkan
#include "../Backend/Vulkan/VulkanContext.h"

#if defined(FUSION_PLATFORM_WINDOWS)

#endif

namespace Fusion
{
	Scope<RendererContext> RendererContext::Create(void* window, uint32_t width, uint32_t height, bool vsync)
	{
		switch (Renderer::GetAPI())
		{
		case Fusion::RendererAPIType::Vulkan:
			return CreateScope<VulkanContext>(static_cast<GLFWwindow*>(window), width, height, vsync);
		}

		FUSION_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}