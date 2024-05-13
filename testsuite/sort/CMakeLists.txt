# SPDX-License-Identifier: GPL-2.0-or-later
#
# Copyright(c) 2024 John Sanpe <sanpeqf@gmail.com>
#

add_executable(sort-fuzzy fuzzy.c)
target_link_libraries(sort-fuzzy bfdev testsuite)
add_test(sort-fuzzy sort-fuzzy)

if(${CMAKE_PROJECT_NAME} STREQUAL "bfdev")
    install(TARGETS
        sort-fuzzy
        DESTINATION
        ${CMAKE_INSTALL_DOCDIR}/testsuite
    )
endif()
