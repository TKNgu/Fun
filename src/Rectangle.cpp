#include "Rectangle.hpp"

#include "OpenGLUtility.hpp"

using namespace glm;

Rectangle::Rectangle(vec3 a, vec3 b, vec3 c, vec3 d) : DrawVertex() {

    float vertices[] = {
        a.x, a.y, a.z,
        b.x, b.y, b.z,
        c.x, c.y, c.z,
        d.x, d.y, d.z,};

    unsigned int indices[] {
        0, 1, 3,
        1, 2, 3,
    };

    glGenBuffers(1, &this->EBO);

    DrawVertex::bufferData(vertices, sizeof (vertices));
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 3 * sizeof (float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof (indices), indices, GL_STATIC_DRAW);
}

Rectangle::Rectangle(vec3 a, vec3 b, vec3 c, vec3 d,
                     vec4 aC, vec4 bC, vec4 cC, vec4 dC) : DrawVertex() {

    float vertices[] = {
        a.x, a.y, a.z, aC.r, aC.g, aC.b, aC.a,
        b.x, b.y, b.z, bC.r, bC.g, bC.b, bC.a,
        c.x, c.y, c.z, cC.r, cC.g, cC.b, cC.a,
        d.x, d.y, d.z, dC.r, dC.g, dC.b, dC.a,};

    unsigned int indices[] {
        0, 1, 3,
        1, 2, 3,
    };

    glGenBuffers(1, &this->EBO);

    DrawVertex::bufferData(vertices, sizeof (vertices));
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 7 * sizeof (float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 4, GL_FLOAT, GL_TRUE, 7 * sizeof (float), (void*)(3 * sizeof (float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof (indices), indices, GL_STATIC_DRAW);
}

Rectangle::~Rectangle() {
    glDeleteBuffers(1, &this->EBO);
}

void Rectangle::render(mat4) const {
    static auto shaderProgram = OpenGLUtility::BuildSimpleShaderProgram();
    shaderProgram.use();
    DrawVertex::bindVertexArray();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Rectangle::update(float) {
    //TODO
}
