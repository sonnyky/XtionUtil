cmake_minimum_required(VERSION 2.8)

project (XtionCapture)
set(CMAKE_BUILD_TYPE Release)


# Set installation folder
set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "default install path" FORCE )


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_library(XtionCapture SHARED main.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/common.hpp)