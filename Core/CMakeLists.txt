file(GLOB_RECURSE sources src/*.cpp src/*.c)
file(GLOB_RECURSE includes include/**/*.h include/Core/EntryPoint.h)
add_library(Core STATIC ${sources} ${includes})
set(CMAKE_CXX_STANDARD 20)
target_include_directories(Core PUBLIC 
    ${CMAKE_CURRENT_SOURCE_DIR}/include 
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glm/
    ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui
    ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/include)

#GLFW
add_subdirectory(external/glfw)
target_link_libraries(Core PRIVATE glfw opengl32)
#GLFW END
    
#GLM
add_subdirectory(external/glm)
target_link_libraries(Core PRIVATE glm)
#GLM END

#IMGUI
set(imgui_dir  ${CMAKE_CURRENT_SOURCE_DIR}/external/imgui)
file(GLOB imgui_core ${imgui_dir}/*.h ${imgui_dir}/*.cpp)
file(GLOB imgui_backend 
            ${imgui_dir}/backends/imgui_impl_opengl3_loader.h 
            ${imgui_dir}/backends/imgui_impl_opengl3.cpp 
            ${imgui_dir}/backends/imgui_impl_opengl3.h 
            ${imgui_dir}/backends/imgui_impl_glfw.h
            ${imgui_dir}/backends/imgui_impl_glfw.cpp
            )

add_library(imgui ${imgui_core} ${imgui_backend}
        include/Core/EntryPoint.h)
target_include_directories(imgui PUBLIC ${imgui_dir} ${imgui_dir}/backends)
target_link_libraries(imgui glfw opengl32)
target_include_directories(Core PUBLIC ${imgui_dir})
target_link_libraries(Core PUBLIC imgui)
#IMGUI END