#include "Sprite.hpp"

#include <glad/glad.h>

using namespace glm;

Sprite::Sprite(vec3 a, vec3 b, vec3 c, vec3 d) : Rectangle(a, b, c, d) {

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

Sprite::~Sprite() {
    glDeleteBuffers(1, &this->EBO);
}
