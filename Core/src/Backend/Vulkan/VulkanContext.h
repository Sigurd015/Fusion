#pragma once
#include "Vulkan.h"
#include "VulkanDevice.h"
#include "VulkanSwapChain.h"
#include "RendererContext.h"

#include <GLFW/glfw3.h>

namespace Fusion
{
	class VulkanContext : public RendererContext
	{
	public:
		VulkanContext(GLFWwindow* windowHandle, uint32_t width, uint32_t height, bool vsync);
		~VulkanContext();

		static VkInstance GetInstance() { return s_VulkanInstance; }

	private:
		void CreateInstance();

		inline static VkInstance s_VulkanInstance;
		VkDebugUtilsMessengerEXT m_DebugUtilsMessenger = VK_NULL_HANDLE;

		Ref<VulkanPhysicalDevice> m_PhysicalDevice;
		Ref<VulkanDevice> m_Device;
		Ref<VulkanSwapChain> m_SwapChain;
	};
}