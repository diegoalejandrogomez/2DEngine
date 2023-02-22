cmake_minimum_required(VERSION 3.24)
project(GameEngine CXX)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_STANDARD 17)

add_compile_definitions(_UNICODE)
# wxWidgets is a bit problematic to compile it in a generic way
if(APPLE)
    link_directories(${CMAKE_SOURCE_DIR}//ThirdParty//wxWidgets//build//lib)
    add_compile_options(-I${CMAKE_SOURCE_DIR}//ThirdParty//wxWidgets//build//lib//wx//include//osx_cocoa-unicode-3.2 -I${CMAKE_SOURCE_DIR}//ThirdParty//wxWidgets//include -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXMAC__ -D__WXOSX__ -D__WXOSX_COCOA__ )
    include_directories(${CMAKE_SOURCE_DIR}//ThirdParty//wxWidgets//build//lib//wx//include//osx_cocoa-unicode-3.2)
endif(APPLE)

if (UNIX)
    include_directories(${CMAKE_SOURCE_DIR}//ThirdParty//wxWidgets//include)
    include_directories(${CMAKE_SOURCE_DIR}//ThirdParty//wxWidgets//build//lib//wx//include//gtk3-unicode-3.2)
    link_directories(${CMAKE_SOURCE_DIR}//ThirdParty//wxWidgets//build//lib)
    add_compile_options(-I${CMAKE_SOURCE_DIR}//ThirdParty//wxWidgets//build//lib//wx//include//gtk3-unicode-3.2 -I${CMAKE_SOURCE_DIR}//ThirdParty//wxWidgets//include -DWXUSINGDLL -D__WXGTK3__ -D__WXGTK__ -pthread)

endif(UNIX)

if (MSVC)
    include_directories(${CMAKE_SOURCE_DIR}//ThirdParty//wxWidgets//include//msvc)
    include_directories(${CMAKE_SOURCE_DIR}//ThirdParty//wxWidgets//include)
    link_directories(${CMAKE_SOURCE_DIR}//ThirdParty//wxWidgets//lib//vc_x64_lib)
endif (MSVC)

file(GLOB_RECURSE HEADERS
	"${CMAKE_SOURCE_DIR}//include//src//App//*.h")
file(GLOB_RECURSE SOURCES, "${CMAKE_SOURCE_DIR}//include//src//App//*.cpp")


add_executable(GameEngine "${CMAKE_SOURCE_DIR}//src//main.cpp" ${HEADERS} ${SOURCES} CMakeLists.txt)

if(APPLE)
    target_link_libraries(GameEngine libwx_osx_cocoau_core-3.2.0.dylib)
    target_link_libraries(GameEngine libwx_baseu-3.2.0.dylib)
endif(APPLE)

if (UNIX)
    target_link_libraries(GameEngine libwx_gtk3u_core-3.2.so)
    target_link_libraries(GameEngine libwx_gtk3u_gl-3.2.so)
    target_link_libraries(GameEngine libwx_baseu-3.2.so)
endif(UNIX)