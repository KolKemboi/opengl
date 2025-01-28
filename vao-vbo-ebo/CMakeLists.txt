cmake_minimum_required(VERSION 3.29)
project(buffers)

set(EXECUTABLE_NAME "buffers")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/../ExternalSource/include)

add_executable(
    ${EXECUTABLE_NAME}
    src/main.cpp
    ${CMAKE_SOURCE_DIR}/../ExternalSource/glad.c
)

target_link_libraries(
    ${EXECUTABLE_NAME}
    ${CMAKE_SOURCE_DIR}/../ExternalSource/libs/libglfw3.a
    opengl32
)