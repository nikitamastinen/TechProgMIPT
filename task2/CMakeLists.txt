cmake_minimum_required(VERSION 3.0)

project(task2 LANGUAGES CXX)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

execute_process(COMMAND python3 preparing.py WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/A)

add_subdirectory(B ${PROJECT_SOURCE_DIR}/lib)

add_executable(C C/main.cpp)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/bin)

target_link_libraries(C lib)
target_include_directories(C PUBLIC "${CMAKE_CURRENT_LIST_DIR}")



