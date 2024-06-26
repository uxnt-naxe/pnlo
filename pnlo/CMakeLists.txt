cmake_minimum_required(VERSION 3.19)
set(CMAKE_CXX_STANDARD 17)

project("pnlo")

# C++17 - 32bit static libgcc
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_C_STANDARD 17)

IF(CMAKE_SYSTEM_NAME MATCHES "Windows")
	set(CMAKE_CXX_FLAGS "-static")
ENDIF()

# set(CMAKE_CXX_FLAGS "-libgcc")
# set(CMAKE_CXX_FLAGS "-m32")

# SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/tcpcode)

# MSVC utf-8
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/source-charset:utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/source-charset:utf-8>")

# GNU utf-8
add_compile_options("$<$<C_COMPILER_ID:GNU>:-fexec-charset=GBK>")
add_compile_options("$<$<CXX_COMPILER_ID:GNU>:-fexec-charset=GBK>")
add_compile_options("$<$<C_COMPILER_ID:GNU>:-finput-charset=utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:GNU>:-finput-charset=utf-8>")

file(GLOB SRCS
	"./cpp/*"
)

# set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/${IDE_BIN_DIR})
set(EXECUTABLE_OUTPUT_PATH "../../")

add_executable("pnlo" ${SRCS})
