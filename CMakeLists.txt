# SPDX-License-Identifier: Apache-2.0

# Example CMake project for using libmpix on a Zephyr supported board.

cmake_minimum_required(VERSION 3.20)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})

project(app LANGUAGES C)

target_sources(app PRIVATE main.c)

libmpix_init(app)
