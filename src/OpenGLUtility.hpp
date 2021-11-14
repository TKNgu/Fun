#ifndef OPENGLUTILITY_HPP
#define OPENGLUTILITY_HPP

#include <string>
#include <filesystem>
#include <functional>
#include "ShaderProgram.hpp"
#include "glm/glm.hpp"

using TransformsFunction = std::function<glm::mat4 (glm::mat4)>;

class OpenGLUtility {
public:
    static const ShaderProgram BuildSimpleShaderProgram();
    static std::string LoadFileText(std::filesystem::path);
    static const TransformsFunction translate(glm::vec3);
    static const TransformsFunction rotate(float, glm::vec3);
    static const TransformsFunction scale(glm::vec3);
};

#endif // OPENGLUTILITY_HPP
