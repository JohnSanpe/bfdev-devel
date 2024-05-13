# SPDX-License-Identifier: GPL-2.0-or-later
#
# Copyright(c) 2023 ffashion <helloworldffashion@gmail.com>
#

add_executable(sort-benchmark benchmark.c)
target_link_libraries(sort-benchmark bfdev)
add_test(sort-benchmark sort-benchmark)

if(${CMAKE_PROJECT_NAME} STREQUAL "bfdev")
    install(FILES
        benchmark.c
        DESTINATION
        ${CMAKE_INSTALL_DOCDIR}/examples/sort
    )

    install(TARGETS
        sort-benchmark
        DESTINATION
        ${CMAKE_INSTALL_DOCDIR}/bin
    )
endif()
