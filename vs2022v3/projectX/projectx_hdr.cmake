## Script for enumerating RemoteCli header files
set(__projectx_hdr_dir ${CMAKE_CURRENT_SOURCE_DIR}/projectx/include)

### Enumerate RemoteCli header files ###
message("[${PROJECT_NAME}] Indexing header files..")
set(__projectx_hdrs
    ${__projectx_hdr_dir}/projectx.h
)

## Use cli_srcs in project CMakeLists
set(projectx_hdrs ${__projectx_hdrs})
