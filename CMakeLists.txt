cmake_minimum_required(VERSION 3.24)

set(PROJECT_NAME CourseWorkOOP)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_link_options(-static)

set(SCRIPTS_DIR "assets/scripts")
add_subdirectory(${SCRIPTS_DIR})

add_executable(${PROJECT_NAME} main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML_mingw64/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

set(SFML_INCLUDE_DIR "C:/SFML_mingw64/include")
include_directories(${SFML_INCLUDE_DIR})

set(SFML_LIBS sfml-system sfml-window sfml-graphics sfml-audio)
target_link_libraries(${PROJECT_NAME} PUBLIC ${SFML_LIBS})

set(DEBUG_BIN_DIR ${CMAKE_SOURCE_DIR}/bin/debug)
set(RELEASE_BIN_DIR ${CMAKE_SOURCE_DIR}/bin/release)
set(DEBUG_PROJECT_NAME ${PROJECT_NAME}_debug)

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY_DEBUG ${DEBUG_BIN_DIR}
        RUNTIME_OUTPUT_DIRECTORY_RELEASE ${RELEASE_BIN_DIR}
        RUNTIME_OUTPUT_NAME_DEBUG ${DEBUG_PROJECT_NAME})

set(MATERIALS_DIR assets/materials)

set(DEBUG_SRC_DIR ${DEBUG_BIN_DIR})
set(RELEASE_SRC_DIR ${RELEASE_BIN_DIR})

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    file(REMOVE_RECURSE ${DEBUG_BIN_DIR})
    file(COPY ${MATERIALS_DIR}
            DESTINATION ${DEBUG_SRC_DIR})
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Release")
    file(REMOVE_RECURSE ${RELEASE_BIN_DIR})
    file(COPY ${MATERIALS_DIR}
            DESTINATION ${RELEASE_SRC_DIR})
endif ()