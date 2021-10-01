#ifndef __WINDOW_HPP__
#define __WINDOW_HPP__

#include <string>

enum OpenGLType {GL3, GL4, GLES, VULKAN};

class Window {
public:
	Window(std::string = "Hello", OpenGLType = OpenGLType::GL3,
		unsigned int = 640, unsigned int = 480,
		unsigned int = 100, unsigned int = 100);
	~Window();
	void render() const;
private:
	std::string name;
	const OpenGLType glType;
	unsigned int width;
	unsigned int height;
	unsigned int x;
	unsigned int y;
};

#endif