# Copyright (c) 2024 Pawel Piskorz
# Licensed under the Eclipse Public License 2.0
# See attached LICENSE file

cmake_minimum_required(VERSION 3.16.3)
project(prir VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 11)

file(GLOB lib_dirs RELATIVE ${CMAKE_SOURCE_DIR} libs/*)
foreach(lib_dir ${lib_dirs})
    if(IS_DIRECTORY ${CMAKE_SOURCE_DIR}/${lib_dir})
        message(STATUS "Adding subdirectory: '" ${lib_dir} "'")
        add_subdirectory(${lib_dir})
    endif()
endforeach()

add_executable(${CMAKE_PROJECT_NAME}
    src/main.cpp
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
	openmp
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
	timing
)

target_link_libraries(${CMAKE_PROJECT_NAME} PRIVATE
	matrix
)

