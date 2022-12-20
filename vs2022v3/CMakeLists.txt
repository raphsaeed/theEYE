cmake_minimum_required(VERSION 3.24)

project(projectX LANGUAGES CXX)

### Append project cmake script dir ###
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/theEYE/cmake ${CMAKE_CURRENT_SOURCE_DIR}/projectX)

### Enumerate project files ###
include(enum_cli_hdr)
include(enum_cli_src)
include(enum_crsdk_hdr)
include(projectx_hdr)
include(projectx_src)

### Define output target ###
set(projectX "${PROJECT_NAME}")
add_executable(${projectX}
    ${cli_hdrs}
    ${cli_srcs}
    ${crsdk_hdrs}
    ${projectx_hdrs}
    ${projectx_srcs}
)

set_target_properties(${projectX} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    BUILD_RPATH "$ORIGIN"
    INSTALL_RPATH "$ORIGIN"
)

## Specify char is signed-char to fix mismatch with Raspbian
target_compile_options(${projectX}
    PRIVATE
        -fsigned-char
)

target_include_directories(${projectX}
    PRIVATE
        ${crsdk_hdr_dir}
        ${cli_hdrs}
)

### Configure external library directories ###
set(ldir ${CMAKE_CURRENT_SOURCE_DIR}/theEYE/external/crsdk)
if(WIN32)
    set(cr_ldir ${ldir}/crsdk_win32)
endif(WIN32)

if(UNIX)
    set(cr_ldir ${ldir}/crsdk_unix)
endif(UNIX)

### Link CRSDK library
find_library(camera_remote Cr_Core HINTS ${cr_ldir})
target_link_libraries(${projectX}
    PRIVATE
        ${camera_remote}
)

### Windows specific configuration ###
if(WIN32)
    ## Build with unicode on Windows
    target_compile_definitions(${projectX} PRIVATE UNICODE _UNICODE)
endif(WIN32)

### Linux specific configuration ###
if(UNIX)
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 8)
            # Must use std::experimental namespace if older than GCC8
            message("[${PROJECT_NAME}] GCC version less than 8. Using std::experimental namespace.")
            target_compile_definitions(${projectX} PRIVATE USE_EXPERIMENTAL_FS)
        endif()

        if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9)
            # Must explicitly link separate std::filesystem if older than GCC9
            message("[${PROJECT_NAME}] GCC version less than 9. Explicitly linking separate std::filesystem library.")
            target_link_libraries(${projectX} PRIVATE stdc++fs)
        endif()
    endif()
endif(UNIX)

## Copy required library binaries
if(WIN32)
    add_custom_command(TARGET ${projectX} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${cr_ldir} $<TARGET_FILE_DIR:${projectX}>
    )
endif(WIN32)

if(UNIX)
    add_custom_command(TARGET ${projectX} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${cr_ldir} $<TARGET_FILE_DIR:${projectX}>
    )
endif(UNIX)

## Install application
## '.' means, install to the root directory of CMAKE_INSTALL_PREFIX
install(TARGETS ${projectX} DESTINATION .)
install(DIRECTORY ${cr_ldir}/ DESTINATION .)
