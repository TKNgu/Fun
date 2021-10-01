#include "Window.hpp"

#include <iostream>
using namespace std;

Window::Window(string name, OpenGLType glType,
	unsigned int width, unsigned int height,
	unsigned int x, unsigned int y) : name(name), glType(glType),
	width(width), height(height), x(x), y(y) {
	cout << "Create Window " << this->name << " type " << this->glType << endl;
	cout << "Size " << this->width << "x" << this->height << endl;
	cout << "Offset " << this->x << "@" << this->y << endl;
}

Window::~Window() {
	cout << "Destroy " << this->name << endl;
}

void Window::render() const {
	cout << "Render " << this->name << endl;
}