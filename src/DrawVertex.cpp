#include "DrawVertex.hpp"

#include <iostream>
#include <glad/glad.h>

using namespace std;

DrawVertex::DrawVertex() {
    glGenVertexArrays(1, &this->VAO);
    glGenBuffers(1, &this->VBO);
}

DrawVertex::~DrawVertex() {
    glDeleteBuffers(1, &this->VBO);
    glDeleteVertexArrays(1, &this->VAO);
}

void DrawVertex::bindVertexArray() const {
    glBindVertexArray(this->VAO);
#ifdef DEBUG_LINE
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
#endif
}

void DrawVertex::bufferData(float* vertices, const std::size_t& sizeVertice) const {
    glBindVertexArray(this->VAO);
    glBindBuffer(GL_ARRAY_BUFFER, this->VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeVertice, vertices, GL_STATIC_DRAW);
}
