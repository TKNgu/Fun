#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <glad/glad.h>

class Shader {
public:
    Shader(const GLenum, const std::string);
    ~Shader();
private:
    friend class ShaderProgram;
    const unsigned int shader;
};

#endif // SHADER_HPP
