#ifndef __WINDOW_BUILDER_HPP__
#define __WINDOW_BUILDER_HPP__

#include <string>
#include "Window.hpp"

class WindowBuilder {
public:
	WindowBuilder& setName(std::string);
	WindowBuilder& setOpenGLType(OpenGLType);
	WindowBuilder& setSize(unsigned int, unsigned int);
	WindowBuilder& setOffset(unsigned int, unsigned int);
	Window build();
private:
	std::string name = "Help";
	OpenGLType glType = OpenGLType::GL3;
	unsigned int width = 640;
	unsigned int height = 480;
	unsigned int x = 100;
	unsigned int y = 100;
};

#endif