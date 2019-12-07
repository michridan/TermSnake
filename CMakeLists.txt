cmake_minimum_required(VERSION 3.8)

project(TermSnake)

add_executable(termSnake main.cpp)

if(WIN32 OR MSVC)
    add_subdirectory(thirdparty/PDCurses-3.9)
    target_link_libraries(termSnake PRIVATE PDCurses)
else()
    find_package(Curses REQUIRED)

    target_include_directories(termSnake PRIVATE ${CMAKE_SOURCE_DIR})
    target_link_libraries(termSnake ${CURSES_LIBRARIES})
endif()
