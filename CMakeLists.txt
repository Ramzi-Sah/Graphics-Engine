#
# File: CMakeLists.txt
#   Author: Ramzi Sah
#
#   Description:
#       handles cmake compilation config

# set cmake min version
cmake_minimum_required(VERSION 3.0.0)

# set c++ compiler min version 
set(CMAKE_CXX_STANDARD 11)

# project name
project (SAHEB_Engine)

# Add source files
file(GLOB_RECURSE SOURCE_FILES
	${CMAKE_SOURCE_DIR}/source/*.cpp
    ${CMAKE_SOURCE_DIR}/source/*/*.cpp
    ${CMAKE_SOURCE_DIR}/source/*/*/*.cpp
    ${CMAKE_SOURCE_DIR}/source/*/*/*/*.cpp
    ${CMAKE_SOURCE_DIR}/source/*/*/*/*/*.cpp
)

# Add header files
file(GLOB_RECURSE HEADER_FILES
	${CMAKE_SOURCE_DIR}/source/*.hpp
	${CMAKE_SOURCE_DIR}/source/*/*.hpp
	${CMAKE_SOURCE_DIR}/source/*/*.hpp
	${CMAKE_SOURCE_DIR}/source/*/*/*.hpp
	${CMAKE_SOURCE_DIR}/source/*/*/*/*.hpp
	${CMAKE_SOURCE_DIR}/source/*/*/*/*/*.hpp
)

# set CMAKE_DIR fot lib loading
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

# OpenGL
find_package(OpenGL REQUIRED)

# GLFW
add_subdirectory(dependencies/glfw-3.3)
include_directories(dependencies/glfw-3.3/include)

# GLAD
add_library(GLAD "dependencies/glad/glad.c")
include_directories("dependencies/glad")

# GLM
include_directories("dependencies/glm")

# imGUI
add_library(imgui
	"dependencies/imgui/imgui_impl_opengl3.cpp"

	"dependencies/imgui/imgui.cpp"
	"dependencies/imgui/imgui_demo.cpp"
	"dependencies/imgui/imgui_draw.cpp"
	"dependencies/imgui/imgui_widgets.cpp"

	"dependencies/imgui/imgui_impl_glfw.cpp"
)
include_directories(
	"dependencies/imgui"
)

# include other dependencies
include_directories("dependencies/others/include")

# build executable
add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})

# Put all libraries into a variable
set(LIBS GLAD glfw imgui)

# Define the link libraries
target_link_libraries(${PROJECT_NAME} ${LIBS})
