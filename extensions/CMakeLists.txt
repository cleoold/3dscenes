cmake_minimum_required(VERSION 3.10)
project(3dscenes_extensions)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic")

add_subdirectory(vendors/lua)

set(CMAKE_EXECUTABLE_SUFFIX ".js")
add_executable(lib_3dscenes_extensions 3dscenes_extensions.cxx)
target_link_libraries(lib_3dscenes_extensions PUBLIC lua::lib)

#if (EMSCRIPTEN)
include_directories("/mnt/c/emsdk/upstream/emscripten/cache/sysroot/include/")  # vscode intellisense only
set_target_properties(lib_3dscenes_extensions PROPERTIES LINK_FLAGS "-s WASM=1 -s EXPORTED_RUNTIME_METHODS='[\"cwrap\"]'")
#endif()

set_target_properties(lib_3dscenes_extensions PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../web)
