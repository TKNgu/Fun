#ifndef __WINDOW_BUILDER_HPP__
#define __WINDOW_BUILDER_HPP__

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "Window.hpp"

class WindowBuilder {
public:
    WindowBuilder(int = 4, int = 1, int = GLFW_OPENGL_CORE_PROFILE);
    WindowBuilder& setName(std::string);
    WindowBuilder& setSize(unsigned int, unsigned int);
    WindowBuilder& setMonitor(GLFWmonitor*, GLFWwindow*);
    Window build();
private:
    const int versionMajor;
    const int versionMinor;
    const int openglProfile;
    std::string name = "Window";
    unsigned int width = 640;
    unsigned int height = 480;
    GLFWmonitor* monitor = nullptr;
    GLFWwindow* share = nullptr;
};

#endif
