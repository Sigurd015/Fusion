#include "VulkanContext.h"

#include <vector>
#include <vulkan/vulkan.h>

#ifdef FUSION_PLATFORM_WINDOWS
#define VK_KHR_PLATFORM_SURFACE_EXTENSION_NAME "VK_KHR_win32_surface"
#elif defined(FUSION_PLATFORM_MACOS)
#define VK_KHR_PLATFORM_SURFACE_EXTENSION_NAME "VK_MVK_macos_surface"
#elif defined(FUSION_PLATFORM_LINUX)
#define VK_KHR_PLATFORM_SURFACE_EXTENSION_NAME "VK_KHR_xcb_surface"
#endif

namespace Fusion
{
	VulkanContext::VulkanContext(GLFWwindow* windowHandle, uint32_t width, uint32_t height, bool vsync)
	{
		VkApplicationInfo appInfo = {};
		appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
		appInfo.pApplicationName = "Hanabi";
		appInfo.pEngineName = "Hanabi";
		appInfo.apiVersion = VK_API_VERSION_1_2;

		VkInstanceCreateInfo instanceCreateInfo = {};
		instanceCreateInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
		instanceCreateInfo.pApplicationInfo = &appInfo;
		instanceCreateInfo.enabledLayerCount = 0;
		instanceCreateInfo.ppEnabledLayerNames = 0;

		std::vector<const char*> instanceExtensions;
		instanceExtensions.push_back(VK_KHR_SURFACE_EXTENSION_NAME);
		instanceExtensions.push_back(VK_KHR_PLATFORM_SURFACE_EXTENSION_NAME);

#ifndef FUSION_DIST
		instanceExtensions.push_back(VK_EXT_DEBUG_UTILS_EXTENSION_NAME);
#endif

		instanceCreateInfo.enabledExtensionCount = (uint32_t)instanceExtensions.size();
		instanceCreateInfo.ppEnabledExtensionNames = instanceExtensions.data();

#ifndef FUSION_DIST
		const char* validationLayerName = "VK_LAYER_KHRONOS_validation";

		uint32_t instanceLayerCount;
		vkEnumerateInstanceLayerProperties(&instanceLayerCount, nullptr);
		std::vector<VkLayerProperties> instanceLayerProperties(instanceLayerCount);
		vkEnumerateInstanceLayerProperties(&instanceLayerCount, instanceLayerProperties.data());
		bool validationLayerPresent = false;

		for (const VkLayerProperties& layer : instanceLayerProperties)
		{
			if (strcmp(layer.layerName, validationLayerName) == 0)
			{
				validationLayerPresent = true;
				break;
			}
		}

		if (validationLayerPresent)
		{
			instanceCreateInfo.enabledLayerCount = 1;
			instanceCreateInfo.ppEnabledLayerNames = &validationLayerName;
		}
		else
		{
			FUSION_ERROR("Validation layer VK_LAYER_KHRONOS_validation not present!");
		}
#endif
	}

	VulkanContext::~VulkanContext()
	{
	}

	void VulkanContext::SwapBuffer(bool VSync)
	{
	}
}