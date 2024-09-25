#include "Fusion.h"
#include "Test.h"

#include <GLFW/glfw3.h>
#include <iostream>

#if defined(PLATFORM_WINDOWS)
#include <Windows.h>
#include <GLFW/glfw3native.h>
#endif

int main(int argc, char** argv)
{
	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	std::string title = "Fusion Test";

	// Set the renderer config
	Fusion::RendererConfig config;
	config.APIType = Fusion::RendererAPIType::Vulkan;
	Fusion::Renderer::SetConfig(config);

	uint32_t wnd_width = 1920;
	uint32_t wnd_height = 1080;
	bool wnd_vsync = true;

	GLFWwindow* window = glfwCreateWindow(wnd_width, wnd_height, title.c_str(), NULL, NULL);
	if (!window)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	switch (config.APIType)
	{
	case Fusion::RendererAPIType::Vulkan:
		title += " <Vulkan>";
		break;

#if defined(FUSION_PLATFORM_WINDOWS)
	case Fusion::RendererAPIType::DX12:
		title += " <DX12>";
		break;
#endif

#if defined(FUSION_PLATFORM_MACOS)
	case Fusion::RendererAPIType::Metal:
		title += " <Metal>";
		break;
#endif
	}

	glfwSetWindowTitle(window, title.c_str());

	Fusion::Renderer::Init(glfwGetWin32Window(window), &wnd_width, &wnd_height, wnd_vsync);

	BaseTest* test = new DefaultTest();
	test->OnAttach();

	float lastFrameTime = 0.0f;
	while (!glfwWindowShouldClose(window))
	{
		float time = glfwGetTime();
		float timestep = time - lastFrameTime;
		lastFrameTime = time;

		test->OnUpdate(timestep);

		glfwPollEvents();
	}

	test->OnDetach();

	glfwDestroyWindow(window);
	glfwTerminate();
	return 0;
}