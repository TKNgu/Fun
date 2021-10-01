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

#endif
