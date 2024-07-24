cmake_minimum_required(VERSION 3.5)
project(REQ_REP)

# 设置C++标准
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 设置ZeroMQ的头文件和库文件路径（根据您的系统情况修改这些路径）
SET(ZeroMQ_INCLUDE_DIRS "/usr/include/zeromq")
SET(ZeroMQ_LIBRARIES "/usr/lib/x86_64-linux-gnu/libzmq.so")

# 包含ZeroMQ头文件
include_directories(${ZeroMQ_INCLUDE_DIRS})

# 添加服务器端可执行文件
add_executable(server src/server.cpp)
# 链接ZeroMQ库到服务器端可执行文件
target_link_libraries(server ${ZeroMQ_LIBRARIES})

# 添加客户端可执行文件
add_executable(client src/client.cpp)

# 链接ZeroMQ库到客户端可执行文件
target_link_libraries(client ${ZeroMQ_LIBRARIES})