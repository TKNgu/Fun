#include "WindowBuilder.hpp"

using namespace std;

WindowBuilder& WindowBuilder::setName(string name) {
	this->name = name;
	return *this;
}

WindowBuilder& WindowBuilder::setOpenGLType(OpenGLType glType) {
	this->glType = glType;
	return *this;
}

WindowBuilder& WindowBuilder::setSize(unsigned int width, unsigned int heigth) {
	this->width = width;
	this->height = height;
	return *this;
}

WindowBuilder& WindowBuilder::setOffset(unsigned int x, unsigned int y) {
	this->x = x;
	this->y = y;
	return *this;
}

Window WindowBuilder::build() {
	return Window(this->name, this->glType, this->width, this->height, this->x, this->y);
}