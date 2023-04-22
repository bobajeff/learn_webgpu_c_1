cmake_minimum_required(VERSION 3.1...3.25)
project(
	LearnWebGPU
	VERSION 0.1.0
	LANGUAGES CXX C
)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
include(FetchContent)

# fetch webgpu deoendency
FetchContent_Declare(
  webgpu
  GIT_REPOSITORY https://github.com/eliemichel/WebGPU-distribution
  GIT_TAG        main
)
FetchContent_MakeAvailable(webgpu)
# Include glfw directory, to define the 'glfw' target
add_subdirectory(glfw)
add_subdirectory(glfw3webgpu)
add_subdirectory(cglm)

add_library(helper helper.c)
target_include_directories(helper PUBLIC ${CMAKE_SOURCE_DIR})
target_link_libraries(helper PRIVATE webgpu)

include(1_getting_started/binaries.cmake)
include(2_hello_triangle/binaries.cmake)
include(3_input_geometry/binaries.cmake)
include(4_uniforms/binaries.cmake)
include(5_3d_meshes/binaries.cmake)


