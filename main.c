#include <GLFW/glfw3.h>

#include <stdio.h>
// #include <iostream>

int main (int, char**) {
	if (!glfwInit()) {
		printf("Could not initialize GLFW!");
		// std::cerr << "Could not initialize GLFW!" << std::endl;
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Learn WebGPU", NULL, NULL);
	if (!window) {
		printf("Could not open window!");
		// std::cerr << "Could not open window!" << std::endl;
		glfwTerminate();
		return 1;
	}

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();

	return 0;
}