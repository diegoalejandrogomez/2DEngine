cmake_minimum_required(VERSION 3.24)
project(Editor CXX)

#*********************************** EXTERNAL LIBRARIES ************************************

#******************************** wxWidgets ***************************************
# wxWidgets is a bit problematic to compile it in a generic way
add_compile_definitions(_UNICODE)

if(APPLE)
    link_directories(${DEPENDENCY_PATH}//wxWidgets//build//lib)
    add_compile_options(-I${DEPENDENCY_PATH}//wxWidgets//build//lib//wx//include//osx_cocoa-unicode-3.2 -I${DEPENDENCY_PATH}//wxWidgets//include -D_FILE_OFFSET_BITS=64 -DWXUSINGDLL -D__WXMAC__ -D__WXOSX__ -D__WXOSX_COCOA__ )
    include_directories(${DEPENDENCY_PATH}//wxWidgets//build//lib//wx//include//osx_cocoa-unicode-3.2)
endif(APPLE)

if (LINUX)
    include_directories(${DEPENDENCY_PATH}//wxWidgets//include)
    include_directories(${DEPENDENCY_PATH}//wxWidgets//build//lib//wx//include//gtk3-unicode-3.2)
    link_directories(${DEPENDENCY_PATH}//wxWidgets//build//lib)
    add_compile_options(-I${DEPENDENCY_PATH}//wxWidgets//build//lib//wx//include//gtk3-unicode-3.2 -I${DEPENDENCY_PATH}//ThirdParty//wxWidgets//include -DWXUSINGDLL -D__WXGTK3__ -D__WXGTK__ -pthread)
endif(LINUX)

if (MSVC)
    include_directories(${DEPENDENCY_PATH}//wxWidgets//include//msvc)
    include_directories(${DEPENDENCY_PATH}//wxWidgets//include)
    link_directories(${DEPENDENCY_PATH}//wxWidgets//lib//vc_x64_lib)
endif (MSVC)


#*********************************** OWN LIBRARIES ************************************
include_directories(${EDITOR_PATH}//include)
include_directories(${CORE_PATH}//include)


#*********************************** SOURCES ************************************

file(GLOB_RECURSE HEADERS
	"${EDITOR_PATH}//include//*.h")

include_directories(${EDITOR_PATH}//include)
file(GLOB_RECURSE SOURCES 
    "${EDITOR_PATH}//src//*.cpp")


#*********************************** EXECUTABLE ************************************
SOURCE_GROUP(TREE ${EDITOR_PATH} FILES ${SOURCES} ${HEADERS} )
add_executable(Editor ${SOURCES} ${HEADERS} CMakeLists.txt)


#*********************************** LINK OWN LIBRARIES ************************************

target_link_libraries(Editor Core)

#*********************************** LINK EXTERNAL LIBRARIES ************************************

if(APPLE)
    target_link_libraries(Editor libwx_osx_cocoau_core-3.2.0.dylib)
    target_link_libraries(Editor libwx_baseu-3.2.0.dylib)
endif(APPLE)

if (LINUX)
    target_link_libraries(Editor libwx_gtk3u_core-3.2.so)
    target_link_libraries(Editor libwx_gtk3u_gl-3.2.so)
    target_link_libraries(Editor libwx_baseu-3.2.so)
endif(LINUX)