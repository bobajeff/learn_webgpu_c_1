#--------------HELLO GPU
add_executable(hello_webgpu
 hello_webgpu.c
)
target_link_libraries(hello_webgpu PRIVATE glfw webgpu)
target_copy_webgpu_binaries(hello_webgpu)

#---------- ADAPTER
add_executable(adapter
adapter.c
)
target_link_libraries(adapter PRIVATE glfw webgpu glfw3webgpu)
target_copy_webgpu_binaries(adapter)

#---------- DEVICE
add_executable(device
device.c
)
target_link_libraries(device PRIVATE glfw webgpu glfw3webgpu)
target_copy_webgpu_binaries(device)
