#---------- VERTEX_ATTRIBUTE
add_executable(vertex_attribute
3_input_geometry/vertex_attribute.c
)
target_link_libraries(vertex_attribute PRIVATE glfw webgpu glfw3webgpu helper)
target_copy_webgpu_binaries(vertex_attribute)

#---------- MULTIPLE ATTRIBUTES (A)
add_executable(multiple_attributes_a
3_input_geometry/multiple_attributes_a.c
)
target_link_libraries(multiple_attributes_a PRIVATE glfw webgpu glfw3webgpu helper)
target_copy_webgpu_binaries(multiple_attributes_a)

#---------- MULTIPLE ATTRIBUTES (B)
add_executable(multiple_attributes_b
3_input_geometry/multiple_attributes_b.c
)
target_link_libraries(multiple_attributes_b PRIVATE glfw webgpu glfw3webgpu helper)
target_copy_webgpu_binaries(multiple_attributes_b)

#---------- INDEX_BUFFER
add_executable(index_buffer
3_input_geometry/index_buffer.c
)
target_link_libraries(index_buffer PRIVATE glfw webgpu glfw3webgpu helper)
target_copy_webgpu_binaries(index_buffer)

#---------- LOADING_FROM_FILE
add_executable(loading_from_file
3_input_geometry/loading_from_file.c
)
target_link_libraries(loading_from_file PRIVATE glfw webgpu glfw3webgpu helper)
target_copy_webgpu_binaries(loading_from_file)