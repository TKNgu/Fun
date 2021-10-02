#ifndef SHADERPROGRAM_HPP
#define SHADERPROGRAM_HPP

#include <string>

class ShaderProgram
{
public:
    ShaderProgram(const std::string&, const std::string&);
    ~ShaderProgram();
    void use();
private:
    unsigned int shaderProgram;
};

#endif // SHADERPROGRAM_HPP
