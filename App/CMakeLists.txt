set(CMAKE_CXX_STANDARD 20)
add_executable(App main.cpp
        ../Core/include/Core/EntryPoint.h)
target_link_libraries(App PUBLIC Core)