#cmake_minimum_required - cmake минимум требуется? минимальная версия cmake
cmake_minimum_required (VERSION 3.26 FATAL_ERROR)

set(PROJECT_NAME OldGame)

project(${PROJECT_NAME})

add_executable(OldGame src/main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(GLFW_INSTALL OFF CACHE BOOL "" FORCE)

add_subdirectory(external/glfw)
target_link_libraries(${PROJECT_NAME} glfw)

