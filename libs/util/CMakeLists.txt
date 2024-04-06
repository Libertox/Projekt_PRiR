# Copyright (c) 2024 Pawel Piskorz
# Licensed under the Eclipse Public License 2.0
# See attached LICENSE file

cmake_minimum_required(VERSION 3.16.3)
set(LIB_TARGET util)


add_library(${LIB_TARGET}
    src/tables.cpp
    src/random.cpp
    src/files.cpp
)

target_include_directories(${LIB_TARGET} PUBLIC
    include
)
