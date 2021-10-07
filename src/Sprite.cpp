#include "Sprite.hpp"

#include <glad/glad.h>
#include "ShaderProgram.hpp"
#include "Resource.hpp"
#include <filesystem>
#include <iostream>

using namespace glm;
using namespace std;

Sprite::Sprite(vec3 a, vec3 b, vec3 c, vec3 d) : Rectangle(a, b, c, d) {

    float vertices[] = {
        a.x, a.y, a.z, 1.0f, 1.0f,
        b.x, b.y, b.z, 1.0f, 0.0f,
        c.x, c.y, c.z, 0.0f, 0.0f,
        d.x, d.y, d.z, 0.0f, 1.0f};

    unsigned int indices[] {
        0, 1, 3,
        1, 2, 3,
    };

    glGenBuffers(1, &this->EBO);

    DrawVertex::bufferData(vertices, sizeof (vertices));
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_TRUE, 5 * sizeof (float), (void*)0);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_TRUE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof (indices), indices, GL_STATIC_DRAW);
}

Sprite::~Sprite() {
    glDeleteBuffers(1, &this->EBO);
}

void Sprite::render() const {
    static auto shaderProgram = ShaderProgram(Resource::getInstance().loadText("shader/Texture.vs"),
        Resource::getInstance().loadText("shader/Texture.fs"));
    static auto texture = Resource::getInstance().loadTexture("ipad/sprite_sheet.png");

    shaderProgram.use();
    texture.bind();
    DrawVertex::bindVertexArray();
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}
