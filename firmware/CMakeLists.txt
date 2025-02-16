#
# Copyright (c) 2025 Simon Brenninger
# SPDX-License-Identifier: GPLv3
#

cmake_minimum_required(VERSION 3.20.0)

# add smartWatch board directory
list(APPEND BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR})
message(${BOARD_ROOT})
set(BOARD smartWatch)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(smartWatchApp)

file(GLOB_RECURSE app_sources src/*.c)
target_sources(app PRIVATE ${app_sources})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
