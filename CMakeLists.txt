cmake_minimum_required(VERSION 3.5 FATAL_ERROR)

set(PROJ_NAME "sleef_cmake_example")
project (${PROJ_NAME})

set(PROJECT_ROOT_DIR ${PROJECT_SOURCE_DIR})
set(THIRD_PARTY_ROOT_DIR ${PROJECT_ROOT_DIR}/third_party)

set(CMAKE_VERBOSE_MAKEFILE ON)

# setup sleef options:
set(SLEEF_BUILD_DFT OFF CACHE BOOL "Don't build sleef DFT lib" FORCE)
set(SLEEF_BUILD_GNUABI_LIBS OFF CACHE BOOL "Don't build sleef gnuabi libs" FORCE)
set(SLEEF_BUILD_TESTS OFF CACHE BOOL "Don't build sleef tests" FORCE)

add_subdirectory(${THIRD_PARTY_ROOT_DIR}/sleef)

set(SOURCES_FILES ${PROJECT_ROOT_DIR}/csrc/sleef_cmake_example.cpp)
add_executable(${PROJ_NAME} ${SOURCES_FILES})

target_include_directories(${PROJ_NAME} PUBLIC ${CMAKE_BINARY_DIR}/include)
target_link_directories(${PROJ_NAME} PRIVATE ${CMAKE_BINARY_DIR}/third_party/sleef/lib)
target_link_libraries(${PROJ_NAME} PUBLIC sleef)
add_dependencies(${PROJ_NAME} sleef)

if(MSVC)
SET_TARGET_PROPERTIES(${PROJ_NAME} PROPERTIES COMPILE_FLAGS "/arch:AVX2 /arch:AVX512")
else()
SET_TARGET_PROPERTIES(${PROJ_NAME} PROPERTIES COMPILE_FLAGS "-mavx2 -mavx512f")
endif()