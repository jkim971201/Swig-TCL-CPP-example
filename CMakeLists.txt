cmake_minimum_required(VERSION 3.2)

cmake_policy(SET CMP0078 NEW)
cmake_policy(SET CMP0086 NEW)

project(SwigTest VERSION 1
  LANGUAGES CXX
)

set(CMAKE_C_COMPILER "g++")
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb -O3 -DIL_STD -ldl")
set(CMAKE_C_FLAGS "${CMAKE_CXX_FLAGS} -g -ggdb -O3 -DIL_STD -ldl")

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake")

include("add_swig")

# Package Settings
find_package(SWIG REQUIRED)
find_package(TCL REQUIRED)

add_compile_options(-fPIC)

include(UseSWIG)

add_subdirectory(src/swigTest)

message(STATUS "swigTest lib? : ${SWIG_TEST}")

set(SRC src/main.cpp)

# Executable
add_executable(${PROJECT_NAME} ${SRC})

# Include Directory
target_include_directories(${PROJECT_NAME}
  PUBLIC
  ${TK_INCLUDE_PATH} 
  src/swigTest
)

# Link Library
target_link_libraries(${PROJECT_NAME} 
  PUBLIC
  ${TCL_LIBRARY}
  swigTest
)
