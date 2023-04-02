#--------------OPEN_WINDOW
add_executable(open_window
1_getting_started/open_window.c
)

target_link_libraries(open_window PRIVATE glfw)

#--------------HELLO GPU
add_executable(hello_webgpu
 1_getting_started/hello_webgpu.c
)
target_link_libraries(hello_webgpu PRIVATE glfw webgpu)
target_copy_webgpu_binaries(hello_webgpu)

#---------- ADAPTER
add_executable(adapter
1_getting_started/adapter.c
)
target_link_libraries(adapter PRIVATE glfw webgpu glfw3webgpu)
target_copy_webgpu_binaries(adapter)

#---------- DEVICE
add_executable(device
1_getting_started/device.c
)
target_link_libraries(device PRIVATE glfw webgpu glfw3webgpu)
target_copy_webgpu_binaries(device)

#---------- COMMAND_QUEUE
add_executable(command_queue
1_getting_started/command_queue.c
)
target_link_libraries(command_queue PRIVATE glfw webgpu glfw3webgpu)
target_copy_webgpu_binaries(command_queue)

#---------- BUFFERS
add_executable(buffers
1_getting_started/buffers.c
)
target_link_libraries(buffers PRIVATE glfw webgpu glfw3webgpu)
target_copy_webgpu_binaries(buffers)

#---------- FIRST_COLOR
add_executable(first_color
1_getting_started/first_color.c
)
target_link_libraries(first_color PRIVATE glfw webgpu glfw3webgpu)
target_copy_webgpu_binaries(first_color)
