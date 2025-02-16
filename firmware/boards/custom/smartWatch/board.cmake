#
# Copyright (c) 2025 Simon Brenninger
# SPDX-License-Identifier: GPLv3
#

if(CONFIG_SMARTWATCH_FT4232)
board_runner_args(openocd "--use-elf"
  "--config=${BOARD_DIR}/support/openocd_ft4232.cfg")
else()
board_runner_args(openocd
  "--config=${BOARD_DIR}/support/openocd_ft2232.cfg")
endif()

include(${ZEPHYR_BASE}/boards/common/openocd.board.cmake)
