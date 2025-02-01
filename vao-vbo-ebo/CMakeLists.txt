cmake_minimum_required(VERSION 3.29)
set(EXECUTABLE_NAME "buffers_1")

project(${EXECUTABLE_NAME})


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${CMAKE_SOURCE_DIR}/../ExternalSource/include)

add_executable(
    ${EXECUTABLE_NAME}
    src/${EXECUTABLE_NAME}.cpp
    ${CMAKE_SOURCE_DIR}/../ExternalSource/glad.c
)

target_link_libraries(
    ${EXECUTABLE_NAME}
    ${CMAKE_SOURCE_DIR}/../ExternalSource/libs/libglfw3.a
    opengl32
)