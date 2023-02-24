cmake_minimum_required(VERSION 3.24)
project(GameEngine CXX)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 17)

if(UNIX AND NOT APPLE)
    set(LINUX TRUE)
endif()

set(DEPENDENCY_PATH ${CMAKE_SOURCE_DIR}//ThirdParty)
set(ROOT_PATH ${CMAKE_SOURCE_DIR})
set(EDITOR_PATH ${CMAKE_SOURCE_DIR}//Editor)
set(CORE_PATH ${CMAKE_SOURCE_DIR}//Core)

add_subdirectory(Editor)
add_subdirectory(Core)