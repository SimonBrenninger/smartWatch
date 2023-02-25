# SPDX-License-Identifier: Apache-2.0

cmake_minimum_required(VERSION 3.20.0)
# add smartWatch board dir
list(APPEND BOARD_ROOT ${CMAKE_CURRENT_SOURCE_DIR}/../zephyr/)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(smartWatchApp)


target_sources(app PRIVATE
src/main.c
src/adc.c
src/gpio.c
src/mxc400.c
src/pca9957.c
)
