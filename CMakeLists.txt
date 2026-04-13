cmake_minimum_required(VERSION 3.29)
project(GPUDrivenRendering)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_SCAN_FOR_MODULES OFF)

include(Scripts/CMake/functions.cmake)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})

set(SOURCE_FOLDER "${CMAKE_SOURCE_DIR}/Resources")
set(DESTINATION_FOLDER "${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/Resources")

set(SwiftImGui ON)
set(SwiftImGuiGLFW ON)
add_subdirectory(Renderer)
add_subdirectory(External)
add_subdirectory(Utility)
add_subdirectory(Application)
add_subdirectory(Shaders)

add_custom_command(
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${SOURCE_FOLDER} ${DESTINATION_FOLDER}
        OUTPUT ${DESTINATION_FOLDER}
        COMMENT "Copying Resources folder"
)

add_custom_target(CopyResources ALL DEPENDS ${DESTINATION_FOLDER})

