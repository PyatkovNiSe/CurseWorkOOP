cmake_minimum_required(VERSION 3.24)

function(custom_add_library_from_dir TARGET)
    set(SOURCES_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    set(HEADERS_DIR ${CMAKE_CURRENT_SOURCE_DIR})
    file(GLOB TARGET_SOURCES ${SOURCES_DIR}/*.cpp)
    message(${TARGET} " [SOURCES] -> " ${TARGET_SOURCES})
    file(GLOB TARGET_HEADERS ${HEADERS_DIR}/*.h)
    message(${TARGET} " [HEADERS] -> " ${TARGET_HEADERS})

    add_library(${TARGET} ${TARGET_SOURCES} ${TARGET_HEADERS})
    set_target_properties(${TARGET} PROPERTIES LINKER_LANGUAGE CXX)

    target_include_directories(${TARGET} PUBLIC ${HEADERS_DIR})
endfunction()

set(PROJECT_NAME Structopolis)
project(${PROJECT_NAME})

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
add_link_options(-static)

add_executable(${PROJECT_NAME} Main.cpp assets/scripts/utility/Utility.h assets/scripts/ui/Ui.h assets/scripts/gameplay/Gameplay.h assets/scripts/utility/Container.h assets/scripts/Scripts.h assets/scripts/gameplay/Building.h assets/scripts/gameplay/Resources.h assets/scripts/gameplay/Material.h assets/scripts/gameplay/Gold.h assets/scripts/gameplay/Time.h assets/scripts/gameplay/Cell.h assets/scripts/gameplay/ConditionFactory.h assets/scripts/gameplay/BuildingInfo.h assets/scripts/gameplay/Field.h)

set(SCRIPTS_DIR "assets/scripts")
add_subdirectory(${SCRIPTS_DIR})

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR C:/SFML_mingw64/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

set(SFML_INCLUDE_DIR "C:/SFML_mingw64/include")
include_directories(${SFML_INCLUDE_DIR})

target_link_libraries(${PROJECT_NAME} PUBLIC SCRIPTS)

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