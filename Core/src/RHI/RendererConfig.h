#pragma once

#include <memory>

namespace Fusion
{
#define FUSION_ASSERT(...)
#define FUSION_TRACE(...) 
#define FUSION_INFO(...)
#define FUSION_WARN(...)
#define FUSION_ERROR(...)
#define FUSION_CRITICAL(...) 

	template <typename T>
	using Scope = std::unique_ptr<T>;
	template <typename T, typename... Args>
	constexpr Scope<T> CreateScope(Args &&...args)
	{
		return std::make_unique<T>(std::forward<Args>(args)...);
	}

	template <typename T>
	using Ref = std::shared_ptr<T>;
	template <typename T, typename... Args>
	constexpr Ref<T> CreateRef(Args &&...args)
	{
		return std::make_shared<T>(std::forward<Args>(args)...);
	}

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