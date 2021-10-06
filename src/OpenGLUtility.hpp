#ifndef OPENGLUTILITY_HPP
#define OPENGLUTILITY_HPP

#include <string>
#include <filesystem>
#include "ShaderProgram.hpp"

class OpenGLUtility {
public:
    static const ShaderProgram BuildSimpleShaderProgram();
    static std::string LoadFileText(std::filesystem::path);
};

#endif // OPENGLUTILITY_HPP
