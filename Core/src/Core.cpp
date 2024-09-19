#include "Core.h"

#include <iostream>
#include <glm/glm.hpp>

namespace Core
{
	void PrintHelloWorld()
	{
		glm::vec3 vec1(1.0f, 0.0f, 0.0f);
		glm::vec3 vec2(0.0f, 1.0f, 0.0f);
		glm::vec3 result = vec1 + vec2;
		std::cout << "Result: (" << result.x << ", " << result.y << ", " << result.z << ")\n";
		std::cout << "Hello World!\n";
	}
}