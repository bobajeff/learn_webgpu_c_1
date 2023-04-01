cmake_minimum_required(VERSION 3.1...3.25)
project(
	LearnWebGPU
	VERSION 0.1.0
	LANGUAGES CXX C
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Include glfw directory, to define the 'glfw' target
add_subdirectory(glfw)

add_executable(App
	main.c
)

# Add the 'glfw' target as a dependency of our App
target_link_libraries(App PRIVATE glfw)

