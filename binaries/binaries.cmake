add_executable(hello_webgpu
 hello_webgpu.c
)

# Add the 'glfw' target as a dependency of our App
target_link_libraries(hello_webgpu PRIVATE glfw webgpu)

target_copy_webgpu_binaries(hello_webgpu)