cmake_minimum_required(VERSION 3.24)
project(VulkanRenderer CXX)
#*********************************** LIBRARIES ************************************


#*********************************** SOURCES ************************************

file(GLOB_RECURSE HEADERS
	"${VULKAN_RENDERER_PATH}//include//*.h")

include_directories(${VULKAN_RENDERER_PATH}//include)
file(GLOB_RECURSE SOURCES 
    "${VULKAN_RENDERER_PATH}//src//*.cpp")


#*********************************** EXECUTABLE ************************************


SOURCE_GROUP(TREE ${VULKAN_RENDERER_PATH} FILES ${SOURCES} ${HEADERS} )
add_library(VulkanRenderer SHARED ${SOURCES} ${HEADERS} CMakeLists.txt)


target_link_libraries(VulkanRenderer vulkan)