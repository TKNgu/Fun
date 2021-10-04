#include "ShaderProgram.hpp"

#include <stdexcept>
#include <glad/glad.h>
#include "Shader.hpp"

using namespace std;

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
