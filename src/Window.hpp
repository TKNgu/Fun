#ifndef WINDOW_HPP
#define WINDOW_HPP

#include <string>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class Window {
public:
    Window(int, int,
           int, std::string,
           unsigned int, unsigned int,
           GLFWmonitor*, GLFWwindow*);
    ~Window();
    bool getIsClose();
    void swapBuffer();
    void pollEvent();
private:
    static void framebufferSizeCallback(GLFWwindow*, int, int);
private:
    GLFWwindow* pWindow;
};

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
