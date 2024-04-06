# Copyright (c) 2024 Pawel Piskorz
# Licensed under the Eclipse Public License 2.0
# See attached LICENSE file

cmake_minimum_required(VERSION 3.16.3)
set(LIB_TARGET openmp)

add_library(${LIB_TARGET} INTERFACE)

list(APPEND compile_link_options
    # Eanble compilation with OpenMP (options vary depending on the used compiler):
    -fopenmp # gcc, g++
    # -qopenmp # icc
)

target_compile_options(${LIB_TARGET} INTERFACE
    ${compile_link_options}
)

target_link_options(${LIB_TARGET} INTERFACE
    ${compile_link_options}
)
