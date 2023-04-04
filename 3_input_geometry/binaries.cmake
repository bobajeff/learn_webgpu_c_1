#---------- VERTEX_ATTRIBUTE
add_executable(vertex_attribute
3_input_geometry/vertex_attribute.c
)
target_link_libraries(vertex_attribute PRIVATE glfw webgpu glfw3webgpu helper)
target_copy_webgpu_binaries(vertex_attribute)
