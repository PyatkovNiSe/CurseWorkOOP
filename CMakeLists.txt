cmake_minimum_required(VERSION 3.24)
project(CourseWorkOOP)

set(CMAKE_CXX_STANDARD 23)

add_executable(CourseWorkOOP main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML_mingw64/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(C:/SFML_mingw64/include)
target_link_libraries(CourseWorkOOP sfml-system sfml-window sfml-graphics sfml-audio)