#---------- HELPER V3 (mostly so I don't have to figure out why cmake 
#    won't include the 3_input_geometry dir when I add helper_v2 to libraries)
add_library(helper_v3 5_3d_meshes/helper_v3.c)
target_include_directories(helper_v3 PUBLIC ${CMAKE_SOURCE_DIR}/5_3d_meshes)
target_link_libraries(helper_v3 PRIVATE webgpu)

#---------- A_SIMPLE_EXAMPLE
add_executable(a_simple_example
5_3d_meshes/a_simple_example.c
)
target_compile_definitions(a_simple_example PRIVATE
    RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/5_3d_meshes/resources"
)
target_link_libraries(a_simple_example PRIVATE glfw webgpu glfw3webgpu helper_v3)
target_copy_webgpu_binaries(a_simple_example)

#---------- DEPTH_BUFFER
add_executable(depth_buffer
5_3d_meshes/depth_buffer.c
)
target_compile_definitions(depth_buffer PRIVATE
    RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/5_3d_meshes/resources"
)
target_link_libraries(depth_buffer PRIVATE glfw webgpu glfw3webgpu helper_v3)
target_copy_webgpu_binaries(depth_buffer)

#---------- TRANSFORMATION_MATRICES
add_executable(transformation_matrices
5_3d_meshes/transformation_matrices.c
)
target_compile_definitions(transformation_matrices PRIVATE
    RESOURCE_DIR="${CMAKE_CURRENT_SOURCE_DIR}/5_3d_meshes/resources"
)
target_link_libraries(transformation_matrices PRIVATE glfw webgpu glfw3webgpu cglm helper_v3)
target_copy_webgpu_binaries(transformation_matrices)
