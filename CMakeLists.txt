cmake_minimum_required(VERSION 3.18)

include(FetchContent)

project(x11demo VERSION 0.1 LANGUAGES C)

find_package(X11 REQUIRED)

add_executable(x11demo main.c)

set_property(TARGET x11demo PROPERTY C_STANDARD 11)

target_link_libraries(x11demo PRIVATE ${X11_LIBRARIES})

target_include_directories(x11demo PRIVATE ${X11_INCLUDE_DIR})