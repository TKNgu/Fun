#include "Triangle.hpp"

#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ShaderProgram.hpp"
#include "OpenGLUtility.hpp"

using namespace std;
using namespace glm;

const ShaderProgram* Triangle::shaderProgram = nullptr;

Triangle::Triangle(vec3 a, vec3 b, vec3 c) : DrawVertex() {
    static const ShaderProgram& tmp = OpenGLUtility::BuildSimpleShaderProgram();
    Triangle::shaderProgram = &tmp;

    float vertices[] = {
        a.x, a.y, a.z,
        b.x, b.y, b.z,
        c.x, c.y, c.z,
    };

    DrawVertex::bufferData(vertices, sizeof (vertices));
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 3 * sizeof (float), (void*)0);
    glEnableVertexAttribArray(0);
}

Triangle::Triangle(vec3 a, vec3 b, vec3 c,
                   vec4 aC, vec4 bC, vec4 cC) : DrawVertex() {
    static const ShaderProgram& tmp = OpenGLUtility::BuildSimpleShaderProgram();
    Triangle::shaderProgram = &tmp;

    float vertices[] = {
        a.x, a.y, a.z, aC.r, aC.g, aC.b, aC.a,
        b.x, b.y, b.z, aC.r, bC.g, bC.b, bC.a,
        c.x, c.y, c.z, aC.r, cC.g, cC.b, cC.a,
    };

    DrawVertex::bufferData(vertices, sizeof (vertices));
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 7 * sizeof (float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, 7 * sizeof (float), (void*)(3 * sizeof (float)));
    glEnableVertexAttribArray(1);
}


void Triangle::render() const {
    Triangle::shaderProgram->use();
    DrawVertex::bindVertexArray();
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
