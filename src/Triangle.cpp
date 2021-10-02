#include "Triangle.hpp"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ShaderProgram.hpp"

using namespace std;

ShaderProgram* Triangle::shaderProgram = nullptr;

ShaderProgram Triangle::BuildShaderProgram() {
    const string vertexShaderSource = "#version 330 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "void main () {\n"
        "   gl_Position = vec4(aPos, 1.0f);\n"
        "}\0";

    const string fragmentShaderSource = "#version 330 core\n"
        "out vec4 FragColor;\n"
        "void main () {\n"
        "   FragColor = vec4(1.0f, 1.0f, 0.2f, 1.0f);\n"
        "}\0";

    return ShaderProgram(vertexShaderSource, fragmentShaderSource);
}

Triangle::Triangle() {
    static auto tmp = BuildShaderProgram();
    Triangle::shaderProgram = &tmp;


}

void Triangle::render() {
    float vertices[] = {
        -0.5f, -0.5f, 0.0f,
        0.5f,  -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    unsigned int VBO;
    glGenBuffers(1, &VBO);

    unsigned int VAO;
    glGenVertexArrays(1, &VAO);

    glBindVertexArray(VAO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    Triangle::shaderProgram->use();
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
