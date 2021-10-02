#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "ShaderProgram.hpp"

class Triangle {
public:
    Triangle();
    void render();
private:
    static ShaderProgram BuildShaderProgram();
    static ShaderProgram* shaderProgram;
};

#endif // TRIANGLE_HPP
