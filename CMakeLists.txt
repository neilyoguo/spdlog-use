#cmake 版本要求
cmake_minimum_required(VERSION  3.22.0)

set(CMAKE_CXX_COMPILER /usr/bin/g++)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-Wall -g -pthread")
#项目信息

project(test)

#向工程添加多个指定头文件的搜索路径
include_directories (include)
include_directories (./pro)
#执行生成目标
set (EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)
aux_source_directory(./pro DIR_SRCS)
add_executable(test ${DIR_SRCS})


