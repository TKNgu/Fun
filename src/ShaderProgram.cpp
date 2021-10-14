#include "ShaderProgram.hpp"

#include <iostream>
#include <stdexcept>
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.hpp"

using namespace std;
using namespace glm;

#define LOG_SIZE 512

ShaderProgram::ShaderProgram(const string& vertexShaderSource,
                             const string& fragmentShaderSource) {
    Shader vertexShader(GL_VERTEX_SHADER, vertexShaderSource);
    Shader fragmentShader(GL_FRAGMENT_SHADER, fragmentShaderSource);
    this->shaderProgram = glCreateProgram();
    glAttachShader(this->shaderProgram, vertexShader.shader);
    glAttachShader(this->shaderProgram, fragmentShader.shader);
    glLinkProgram(this->shaderProgram);

    static int success = 0;
    static char infoLog[LOG_SIZE];
    glGetProgramiv(this->shaderProgram, GL_LINK_STATUS, &success);
    if (!success) {
        glGetProgramInfoLog(this->shaderProgram, LOG_SIZE, nullptr, infoLog);
        glDeleteProgram(this->shaderProgram);
        throw runtime_error(infoLog);
    }
}

ShaderProgram::~ShaderProgram() {
    glDeleteProgram(this->shaderProgram);
}

void ShaderProgram::use() const {
    glUseProgram(this->shaderProgram);
}

void ShaderProgram::setUniform(mat4 mat, string name) {
//    unsigned int matLoc = glGetUniformLocation(this->shaderProgram, name.c_str());
    unsigned int matLoc = glGetUniformLocation(shaderProgram, "transform");
    if (matLoc < 0) {
        throw runtime_error("Not found key");
    }
    glUniformMatrix4fv(matLoc, 1, true, glm::value_ptr(mat));
//    glUniformMatrix4fv(matLoc, 1, false, glm::value_ptr(mat));

}
