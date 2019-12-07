cmake_minimum_required(VERSION 3.8)

project(TermSnake)

find_package(Curses REQUIRED)

add_executable(termSnake main.cpp)

target_include_directories(termSnake PRIVATE ${CMAKE_SOURCE_DIR})
target_link_libraries(termSnake ${CURSES_LIBRARIES})
