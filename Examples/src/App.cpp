#include "Fusion.h"
#include "Test.h"

#include <GLFW/glfw3.h>
#include <iostream>

#if defined(FUSION_PLATFORM_WINDOWS)
#include <GLFW/glfw3native.h>
#endif

int main(int argc, char **argv)
{
	if (!glfwInit())
	{
		std::cerr << "Failed to initialize GLFW" << std::endl;
		return -1;
	}

	glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);

	std::string title = "Fusion Test";

	GLFWwindow *window = glfwCreateWindow(1920, 1080, title.c_str(), NULL, NULL);
	if (!window)
	{
		std::cerr << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1;
	}

	Fusion::RendererConfig config;
	config.APIType = Fusion::RendererAPIType::Vulkan;
	config.Width = 1920;
	config.Height = 1080;
	config.VSync = true;

	switch (config.APIType)
	{
	case Fusion::RendererAPIType::Vulkan:
		title += " <Vulkan>";
		config.WindowHandle = window;
		break;

#if defined(FUSION_PLATFORM_WINDOWS)
	case Fusion::RendererAPIType::DX12:
		title += " <DX12>";
		//HWND winWnd = glfwGetWin32Window(window);
		//config.WindowHandle = winWnd;
		break;
#endif

#if defined(FUSION_PLATFORM_MACOS)
	case Fusion::RendererAPIType::Metal:
		title += " <Metal>";
		break;
#endif
	}

	glfwSetWindowTitle(window, title.c_str());
	Fusion::Renderer::Init(config);

	BaseTest *test = new DefaultTest();
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