cmake_minimum_required(VERSION 3.20.0)

project(llvm-sra)


if(NOT DEFINED ENV{LLVMINSTALLDIR})
  message(FATAL_ERROR "$LLVMINSTALLDIR is not defined")
endif()

list(APPEND CMAKE_PREFIX_PATH "$ENV{LLVMINSTALLDIR}/lib/cmake/llvm/")
find_package(LLVM REQUIRED CONFIG)

include_directories(${LLVM_INCLUDE_DIRS})
link_directories(${LLVM_LIBRARY_DIRS})
add_definitions(${LLVM_DEFINITIONS})

set(CMAKE_CXX_STANDARD 17 CACHE STRING "")

# Build type
if (NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Debug CACHE
      STRING "Build type (default Debug):" FORCE)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

add_subdirectory(lib)
