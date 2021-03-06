#include "Window.hpp"

#include <iostream>
using namespace std;

Window::Window(int versionMajor, int versionMinor,
                    int openglProfile, string name,
                    unsigned int width, unsigned int height,
                    GLFWmonitor* monitor, GLFWwindow* share) {
    if (glfwInit() == GLFW_FALSE) {
        throw runtime_error("Failed to init GLFW");
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, versionMajor);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, versionMinor);
    glfwWindowHint(GLFW_OPENGL_PROFILE, openglProfile);

#ifndef __OSX__
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif

    this->pWindow = glfwCreateWindow(int(width), int(height), name.c_str(), monitor, share);
    if (this->pWindow == nullptr) {
        glfwTerminate();
        throw runtime_error("Failed to create GLFW window");
    }
    glfwMakeContextCurrent(this->pWindow);
    if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress))) {
        glfwTerminate();
        throw runtime_error("Failed to initalize GLAD");
    }
    glfwSetFramebufferSizeCallback(this->pWindow, Window::framebufferSizeCallback);
}

Window::~Window() {
    glfwDestroyWindow(this->pWindow);
    glfwTerminate();
}

bool Window::getIsClose() {
    return glfwWindowShouldClose(this->pWindow);
}

void Window::swapBuffer() {
    glfwSwapBuffers(this->pWindow);
}

void Window::pollEvent() {
    glfwPollEvents();
}

void Window::framebufferSizeCallback(GLFWwindow* window, int width, int height) {
    glViewport(0, 0, width, height);
}

WindowBuilder::WindowBuilder(int versionMajor, int versionMinor, int openglProfile):
        versionMajor(versionMajor), versionMinor(versionMinor), openglProfile(openglProfile) {
    //TODO
}

WindowBuilder& WindowBuilder::setName(string name) {
    this->name = name;
    return *this;
}

WindowBuilder& WindowBuilder::setSize(unsigned int width, unsigned int height) {
    this->width = width;
    this->height = height;
    return *this;
}

WindowBuilder& WindowBuilder::setMonitor(GLFWmonitor* monitor, GLFWwindow* share) {
    this->monitor = monitor;
    this->share = share;
    return *this;
}

Window WindowBuilder::build() {
    return Window(this->versionMajor, this->versionMinor, this->openglProfile,
                  this->name, this->width, this->height, this->monitor, this->share);
}
