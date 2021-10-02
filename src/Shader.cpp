#include "Shader.hpp"

#include <stdexcept>
#include <iostream>

using namespace std;

#define LOG_SIZE 512

Shader::Shader(const GLenum type, const string source):
    shader(glCreateShader(type)) {
    const auto tmp = source.c_str();
    glShaderSource(this->shader, 1, &tmp, nullptr);
    glCompileShader(this->shader);

    static int success;
    static char infoLog[LOG_SIZE];
    glGetShaderiv(this->shader, GL_COMPILE_STATUS, &success);
    if (!success) {
        glGetShaderInfoLog(this->shader, LOG_SIZE, nullptr, infoLog);
        glDeleteShader(this->shader);
        throw runtime_error(infoLog);
    }
}

Shader::~Shader() {
    glDeleteShader(this->shader);
}
