#pragma once
#include "Vulkan.h"

#include <unordered_set>

namespace Fusion
{
    class VulkanPhysicalDevice
    {
    public:
        struct QueueFamilyIndices
        {
            int32_t Graphics = -1;
            int32_t Compute = -1;
            int32_t Transfer = -1;
        };
        VulkanPhysicalDevice();
        ~VulkanPhysicalDevice();

        bool IsExtensionSupported(const std::string &extensionName) const;
        uint32_t GetMemoryTypeIndex(uint32_t typeBits, VkMemoryPropertyFlags properties) const;

        VkPhysicalDevice GetVulkanPhysicalDevice() const { return m_PhysicalDevice; }
        const QueueFamilyIndices &GetQueueFamilyIndices() const { return m_QueueFamilyIndices; }

        const VkPhysicalDeviceProperties &GetProperties() const { return m_Properties; }
        const VkPhysicalDeviceLimits &GetLimits() const { return m_Properties.limits; }
        const VkPhysicalDeviceMemoryProperties &GetMemoryProperties() const { return m_MemoryProperties; }

        VkFormat GetDepthFormat() const { return m_DepthFormat; }

        static Ref<VulkanPhysicalDevice> Select();

    private:
        VkFormat FindDepthFormat() const;
        QueueFamilyIndices GetQueueFamilyIndices(int queueFlags);

        QueueFamilyIndices m_QueueFamilyIndices;

        VkPhysicalDevice m_PhysicalDevice = nullptr;
        VkPhysicalDeviceProperties m_Properties;
        VkPhysicalDeviceFeatures m_Features;
        VkPhysicalDeviceMemoryProperties m_MemoryProperties;

        VkFormat m_DepthFormat = VK_FORMAT_UNDEFINED;

        std::vector<VkQueueFamilyProperties> m_QueueFamilyProperties;
        std::unordered_set<std::string> m_SupportedExtensions;
        std::vector<VkDeviceQueueCreateInfo> m_QueueCreateInfos;

        friend class VulkanDevice;
    };

    class VulkanDevice
    {
    public:
        VulkanDevice(const Ref<VulkanPhysicalDevice> &physicalDevice, VkPhysicalDeviceFeatures enabledFeatures);
        ~VulkanDevice();

        void Destroy();

        const Ref<VulkanPhysicalDevice> &GetPhysicalDevice() const { return m_PhysicalDevice; }
        VkDevice GetVulkanDevice() const { return m_LogicalDevice; }

    private:
        VkDevice m_LogicalDevice = nullptr;
        Ref<VulkanPhysicalDevice> m_PhysicalDevice;
        VkPhysicalDeviceFeatures m_EnabledFeatures;

        VkQueue m_GraphicsQueue;
        VkQueue m_ComputeQueue;

        bool m_EnableDebugMarkers = false;
    };
}