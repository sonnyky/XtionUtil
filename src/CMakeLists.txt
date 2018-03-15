cmake_minimum_required(VERSION 2.8)

project (XtionCapture)
set(CMAKE_BUILD_TYPE Release)

set(XTION_INCLUDE_DIRS             "D:/Applications/Xtion2/Installation/Include")
set(XTIONUTIL_INCLUDE_DIRS         "D:/Workspace/XtionUtil/src/include")
set(OPENNI2_LIB_DIR                "D:/Applications/Xtion2/Installation/Lib")
set(OPENNI2_LIBRARIES              ${OPENNI2_LIB_DIR}/OpenNI2.lib)

# Set installation folder
set (CMAKE_INSTALL_PREFIX "${CMAKE_BINARY_DIR}/install" CACHE PATH "default install path" FORCE )


include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${XTION_INCLUDE_DIRS} ${XTIONUTIL_INCLUDE_DIRS})
link_directories(${OPENNI2_LIB_DIR})

# add_library sets the project to build dll libraries. For executables use add_executable instead
add_library(XtionCapture SHARED main.cpp xtion_capture.cpp ${CMAKE_CURRENT_SOURCE_DIR}/include/common.hpp ${CMAKE_CURRENT_SOURCE_DIR}/include/xtion_capture.h)

target_link_libraries(XtionCapture ${OPENNI2_LIBRARIES})