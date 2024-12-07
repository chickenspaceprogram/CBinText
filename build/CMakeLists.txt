#  This Source Code Form is subject to the terms of the Mozilla Public
#  License, v. 2.0. If a copy of the MPL was not distributed with this
#  file, You can obtain one at https://mozilla.org/MPL/2.0/.

cmake_minimum_required(VERSION 3.15)
project(cbintxt C)

set(CMAKE_C_STANDARD 11)

enable_testing()

add_subdirectory(../src ./src)