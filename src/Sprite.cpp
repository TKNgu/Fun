#include "Sprite.hpp"

#include <glad/glad.h>
#include <glm/gtc/matrix_transform.hpp>
#include "ShaderProgram.hpp"
#include "Resource.hpp"
#include <filesystem>
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;
using namespace std;

Sprite::Sprite(const Texture& texture) : DrawVertex(), texture(texture) {
    float vertices[] = {
        1.0f, 1.0f, 0.0f, 1.0f, 1.0f,
        1.0f, -1.0f, 0.0f, 1.0f, 0.0f,
        -1.0f, -1.0f, 0.0f, 0.0f, 0.0f,
        -1.0f, 1.0f, 0.0f, 0.0f, 1.0f};

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

void Sprite::render(mat4 renderMat) const {
    renderMat *= this->modelMat;
    static auto shaderProgram = ShaderProgram(Resource::getInstance().loadText("shader/Texture.vs"),
        Resource::getInstance().loadText("shader/Texture.fs"));
    shaderProgram.use();
    shaderProgram.setUniform(renderMat, "transform");
    glActiveTexture(GL_TEXTURE0);
    this->texture.bind();
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Sprite::update(float) {
    //TODO
}
