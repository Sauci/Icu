cmake_minimum_required(VERSION 3.8.0)

project(Icu VERSION 0.1.0 LANGUAGES C)

set(AUTOSAR_STD_HEADER_PATH ${CMAKE_CURRENT_SOURCE_DIR}/test/stub/common CACHE FILEPATH
    "path to directory containing Std_Types.h and ComStack_Types.h.")
option(ICU_ENABLE_TEST "enables/disables tests." OFF)
option(ENABLE_DET "enables/disables development error detection." ON)

find_package(PythonInterp 3.6 REQUIRED)

add_library(${PROJECT_NAME} source/Icu.c)

target_compile_definitions(${PROJECT_NAME}
    PRIVATE ICU_DEV_ERROR_DETECT=$<IF:$<BOOL:${ENABLE_DET}>,STD_ON,STD_OFF>
    PRIVATE ICU_SW_VERSION_MAJOR=${PROJECT_VERSION_MAJOR}
    PRIVATE ICU_SW_VERSION_MINOR=${PROJECT_VERSION_MINOR}
    PRIVATE ICU_SW_VERSION_PATCH=${PROJECT_VERSION_PATCH}
    PUBLIC ICU_AR_RELEASE_MAJOR_VERSION=4 # SWS_BSW_00059
    PUBLIC ICU_AR_RELEASE_MINOR_VERSION=4
    PUBLIC ICU_API=STD_ON
    PUBLIC ICU_CHECK_WAKEUP_API=STD_OFF
    PUBLIC ICU_BUILD_CFFI_INTERFACE=$<IF:$<BOOL:${ICU_ENABLE_TEST}>,STD_ON,STD_OFF>)

target_include_directories(${PROJECT_NAME}
    PUBLIC interface
    PUBLIC ${AUTOSAR_STD_HEADER_PATH}
    PUBLIC $<$<BOOL:${ICU_ENABLE_TEST}>:${CMAKE_CURRENT_SOURCE_DIR}/test/stub>)

if (${ICU_ENABLE_TEST})
    enable_testing()

    add_test(NAME Icu_UnitTest
        COMMAND ${PYTHON_EXECUTABLE} -W ignore::DeprecationWarning
        -m pytest ${CMAKE_CURRENT_SOURCE_DIR}/test
        --build_directory ${CMAKE_BINARY_DIR}
        --script_directory ${PROJECT_SOURCE_DIR}/script
        --header ${PROJECT_SOURCE_DIR}/interface/Icu.h
        --source ${PROJECT_SOURCE_DIR}/source/Icu.c
        --compile_definitions $<JOIN:$<TARGET_PROPERTY:${PROJECT_NAME},COMPILE_DEFINITIONS>,$<SEMICOLON>>
        --include_directories $<JOIN:$<TARGET_PROPERTY:${PROJECT_NAME},INCLUDE_DIRECTORIES>,$<SEMICOLON>>
        --junitxml=./report/${PROJECT_NAME}.xml
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})
endif ()
