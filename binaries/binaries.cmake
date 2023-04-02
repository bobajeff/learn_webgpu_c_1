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

#---------- COMMAND_QUEUE
add_executable(command_queue
command_queue.c
)
target_link_libraries(command_queue PRIVATE glfw webgpu glfw3webgpu)
target_copy_webgpu_binaries(command_queue)

#---------- BUFFERS
add_executable(buffers
buffers.c
)
target_link_libraries(buffers PRIVATE glfw webgpu glfw3webgpu)
target_copy_webgpu_binaries(buffers)

#---------- FIRST_COLOR
add_executable(first_color
first_color.c
)
target_link_libraries(first_color PRIVATE glfw webgpu glfw3webgpu)
target_copy_webgpu_binaries(first_color)
