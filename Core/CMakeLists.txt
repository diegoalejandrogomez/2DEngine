cmake_minimum_required(VERSION 3.24)
project(Core CXX)
#*********************************** LIBRARIES ************************************

include_directories(${VULKAN_RENDERER_PATH}//include)
#*********************************** SOURCES ************************************

file(GLOB_RECURSE HEADERS
	"${CORE_PATH}//include//*.h")

include_directories(${CORE_PATH}//include)
file(GLOB_RECURSE SOURCES 
    "${CORE_PATH}//src//*.cpp")



#*********************************** EXECUTABLE ************************************


SOURCE_GROUP(TREE ${CORE_PATH} FILES ${SOURCES} ${HEADERS} )
add_library(Core SHARED ${SOURCES} ${HEADERS} CMakeLists.txt)



target_link_libraries(Core VulkanRenderer)