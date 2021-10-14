#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include <string>
#include <glm/glm.hpp>

class ShaderProgram
{
public:
    ShaderProgram(const std::string&, const std::string&);
    ~ShaderProgram();
    void use() const;
    void setUniform(glm::mat4, std::string);
    unsigned int shaderProgram;
};

#endif // SHADERPROGRAM_HPP
