cmake_minimum_required(VERSION 3.24)

project(theEYE LANGUAGES CXX)

### Append project cmake script dir ###
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)

### Enumerate project files ###
include(enum_cli_hdr)
include(enum_cli_src)
include(enum_crsdk_hdr)

### Define output target ###
set(theEYE "${PROJECT_NAME}")
add_executable(${theEYE}
    ${cli_hdrs}
    ${cli_srcs}
    ${crsdk_hdrs}
)

set_target_properties(${theEYE} PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED YES
    CXX_EXTENSIONS NO
    BUILD_RPATH "$ORIGIN"
    INSTALL_RPATH "$ORIGIN"
)

## Specify char is signed-char to fix mismatch with Raspbian
target_compile_options(${theEYE}
    PRIVATE
        -fsigned-char
)

target_include_directories(${theEYE}
    PRIVATE
        ${crsdk_hdr_dir} # defined in enum script
)

### Configure external library directories ###
set(ldir ${CMAKE_CURRENT_SOURCE_DIR}/external/crsdk)
if(WIN32)
    set(cr_ldir ${ldir}/crsdk_win32)
endif(WIN32)

if(UNIX)
    set(cr_ldir ${ldir}/crsdk_unix)
endif(UNIX)

### Link CRSDK library
find_library(camera_remote Cr_Core HINTS ${cr_ldir})
target_link_libraries(${theEYE}
    PRIVATE
        ${camera_remote}
)

### Windows specific configuration ###
if(WIN32)
    ## Build with unicode on Windows
    target_compile_definitions(${theEYE} PRIVATE UNICODE _UNICODE)
endif(WIN32)

### Linux specific configuration ###
if(UNIX)
    if("${CMAKE_CXX_COMPILER_ID}" STREQUAL "GNU")
        if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 8)
            # Must use std::experimental namespace if older than GCC8
            message("[${PROJECT_NAME}] GCC version less than 8. Using std::experimental namespace.")
            target_compile_definitions(${theEYE} PRIVATE USE_EXPERIMENTAL_FS)
        endif()

        if(CMAKE_CXX_COMPILER_VERSION VERSION_LESS 9)
            # Must explicitly link separate std::filesystem if older than GCC9
            message("[${PROJECT_NAME}] GCC version less than 9. Explicitly linking separate std::filesystem library.")
            target_link_libraries(${theEYE} PRIVATE stdc++fs)
        endif()
    endif()
endif(UNIX)

## Copy required library binaries
if(WIN32)
    add_custom_command(TARGET ${theEYE} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${cr_ldir} $<TARGET_FILE_DIR:${theEYE}>
    )
endif(WIN32)

if(UNIX)
    add_custom_command(TARGET ${theEYE} PRE_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${cr_ldir} $<TARGET_FILE_DIR:${theEYE}>
    )
endif(UNIX)

## Install application
## '.' means, install to the root directory of CMAKE_INSTALL_PREFIX
install(TARGETS ${theEYE} DESTINATION .)
install(DIRECTORY ${cr_ldir}/ DESTINATION .)
