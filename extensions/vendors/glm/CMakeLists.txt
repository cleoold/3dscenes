cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

add_library(glm-header INTERFACE)

target_include_directories(glm-header
    INTERFACE
    ${CMAKE_CURRENT_BINARY_DIR}/src)
