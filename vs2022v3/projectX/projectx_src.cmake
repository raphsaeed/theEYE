## Script for enumerating RemoteCli source files
set(__projectx_src_dir ${CMAKE_CURRENT_SOURCE_DIR}/projectX/src)

### Enumerate RemoteCli source files ###
message("[${PROJECT_NAME}] Indexing source files..")
set(__projectx_srcs
    ${__projectx_src_dir}/projectx.cpp
)

## Use cli_srcs in project CMakeLists
set(projectx_srcs ${__projectx_srcs})
