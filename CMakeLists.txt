#Cmake version.
cmake_minimum_required(VERSION 3.10.2)

# C++ std 17.
set(CMAKE_CXX_STANDARD 17)
if (UNIX)
    set(CMAKE_EXE_LINKER_FLAGS "-no-pie")
endif (UNIX)
set(CMAKE_EXE_LINKER_FLAGS)

# Monitor Service.
project(Fun LANGUAGES CXX C)
#add_definitions(-DDEBUG_LINE)

# OPENGL
IF(APPLE)
     SET(CMAKE_CXX_LINK_FLAGS "-framework OpenGL -framework GLUT")
ENDIF(APPLE)
set(CMAKE_CXX_FLAGS " -DIMGUI_IMPL_OPENGL_LOADER_GLAD")

# GLFW
add_subdirectory(extensions/glfw)

# GLM
add_subdirectory(extensions/glm)

# Source code
file(GLOB SRC src/*.cpp src/*.hpp src/glad/src/*.c)

# Include
INCLUDE_DIRECTORIES(lib/include/
        extensions/glfw/include/
        extensions/glm/
        extensions/stb/
        src/glad/include/)

# Link
LINK_DIRECTORIES(${CMAKE_SOURCE_DIR}/lib/lib/)

# Build
add_executable(${CMAKE_PROJECT_NAME} ${SRC})
target_link_libraries(${CMAKE_PROJECT_NAME} glfw)

# Run
add_custom_target(run
	COMMAND ${CMAKE_PROJECT_NAME}
	DEPENDS ${CMAKE_PROJECT_NAME}
	WORKING_DIRECTORY ${CMAKE_PROJECT_DIR})
