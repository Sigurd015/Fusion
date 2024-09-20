#pragma once
#include "../../RHI/RendererContext.h"

#include <GLFW/glfw3.h>

namespace Fusion
{
	class VulkanContext :public RendererContext
	{
	public:
		VulkanContext(GLFWwindow* windowHandle, uint32_t width, uint32_t height, bool vsync);
		~VulkanContext();

		virtual void SwapBuffer(bool VSync) override;
	};
}