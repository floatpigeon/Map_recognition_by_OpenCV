cmake_minimum_required(VERSION 3.12)
project(MRBO)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)

add_executable(MRBO src/main.cpp src/identifier.cpp)
#------------------------------------------------

find_package(Eigen3 REQUIRED NO_MODULE)
target_link_libraries(MRBO Eigen3::Eigen)

find_package(OpenCV REQUIRED)
target_link_libraries(MRBO ${OpenCV_LIBS} pthread)
include_directories(${OpenCV_INCLUDE_DIRS} ${Eigen3_INCLUDE_DIRS})

set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

#------------------------------------------------
# command if error:
# LD_PRELOAD=/lib/x86_64-linux-gnu/libpthread.so.0 ./Project