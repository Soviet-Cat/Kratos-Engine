# ---------------------------------------------------
# Copyright (c) 2025 Soviet-Cat. All Rights Reserved.
# See LICENSE file for details.
# ---------------------------------------------------

cmake_minimum_required(VERSION 3.20)

project(KratosEngine LANGUAGES CXX VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(FRAMEWORK "Build and install 'framework'?" OFF)

set(SRC ${CMAKE_CURRENT_SOURCE_DIR}/src)
set(EXPORT "EXPORT")

if (FRAMEWORK)
    set(KratosFrameworkSources 
        ${SRC}/test.cpp
    )
    set(KratosFrameworkHeaders
        ${SRC}/test.hpp
    )
    add_library(KratosFramework SHARED ${KratosFrameworkSources})
    set_target_properties(KratosFramework PROPERTIES
        OUTPUT_NAME "KratosFramework"
    )
    target_compile_definitions(KratosFramework
        PRIVATE ${EXPORT}
    )
    target_include_directories(KratosFramework
        PUBLIC
            $<BUILD_INTERFACE:${SRC}>
            $<INSTALL_INTERFACE:include>
        PRIVATE
            ${SRC}
    )
    install(
        TARGETS KratosFramework
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION lib
        ARCHIVE DESTINATION lib
    )
    install(
        FILES ${KratosFrameworkHeaders}
        DESTINATION include
    )
endif()