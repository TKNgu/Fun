#include "WindowBuilder.hpp"

using namespace std;

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
