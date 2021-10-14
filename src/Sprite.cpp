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
        1.0f, 0.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f, 0.0f,
        0.0f, 1.0f, 0.0f, 0.0f, 1.0f};

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


void Show(mat4 modelMat) {
    for (int indexY = 0; indexY < 4; indexY++) {
        for (int indexX = 0; indexX < 4; indexX++) {
            std::cout << modelMat[indexX][indexY] << " ";
        }
        std::cout << std::endl;
    }
}

void Sprite::render() const {

    std::string vertexShaderSource("#version 410 core\n"
        "layout (location = 0) in vec3 aPos;\n"
        "layout (location = 1) in vec2 aTexCoord;\n"
        "uniform mat4 transform;\n"
        "out vec2 TexCoord;\n"
        "void main() {\n"
        "   gl_Position = transform * vec4(aPos, 1.0);\n"
        "   TexCoord = aTexCoord;\n"
        "}\0");

    std::string fragmentShaderSource("#version 410 core\n"
        "in vec2 TexCoord;\n"
        "out vec4 FragColor;\n"
        "uniform sampler2D ourTexture;\n"
        "void main() {\n"
            "vec4 texColor = texture(ourTexture, TexCoord);\n"
            "if(texColor.a < 0.1) {\n"
                "discard;\n"
                "}\n"
            "FragColor = texColor;\n"
//            "FragColor = vec4(1.0f, 1.0f, 1.0f, 1.0f);\n"
        "}\0");

//    static auto shaderProgram = ShaderProgram(Resource::getInstance().loadText("shader/Texture.vs"),
//        Resource::getInstance().loadText("shader/Texture.fs"));
    static auto shaderProgram = ShaderProgram(vertexShaderSource, fragmentShaderSource);
    shaderProgram.use();
//    mat4 tmp = mat4(1.0f) * this->modelMat;

    cout << "Endl" << endl;
    mat4 tmp = mat4(1.0f);
    tmp = glm::translate(tmp, vec3(0.5, 0.5, 0.0));
    Show(tmp);

//    exit(0);

    shaderProgram.setUniform(tmp, "transform");
//    this->texture.bind();
//    glBindTexture(GL_TEXTURE_2D, 0);
//    DrawVertex::bindVertexArray();
//    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

//    unsigned int transformLoc = glGetUniformLocation(shaderProgram.shaderProgram, "transform");
//    glUniformMatrix4fv(transformLoc, 1, false, value_ptr(tmp));
    glActiveTexture(GL_TEXTURE0);
    this->texture.bind();
    glBindVertexArray(this->VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

void Test(vec3 vec, glm::mat4 trans) {
    vec = trans * vec4(vec, 1.0f);
    std::cout << vec.x << " " << vec.y << " " << vec.z << std::endl;
}

void Sprite::translate(vec3 vector) {

//    cout << modelMat[0][3] << endl;
//    cout << modelMat[1][3] << endl;
//    cout << modelMat[2][3] << endl;

//    Show(modelMat);
//    cout << endl;

    this->modelMat = glm::translate(this->modelMat, vector);
//    Show(modelMat);
//    cout << endl;

    this->modelMat[0][3] = vector.x;
    this->modelMat[1][3] = vector.y;
    this->modelMat[2][3] = vector.z;
//    Show(modelMat);
//    cout << endl;

//    cout << this->modelMat[0][3] << endl;
//    cout << this->modelMat[1][3] << endl;
//    cout << this->modelMat[2][3] << endl;

//    Test(vec3(1.0f, 1.0f, 0.0f), modelMat);
//    Test(vec3(1.0f, 0.0f, 0.0f), modelMat);
//    Test(vec3(0.0f, 0.0f, 0.0f), modelMat);
//    Test(vec3(0.0f, 1.0f, 0.0f), modelMat);
}

void Sprite::rotate(float angle, glm::vec3 location) {
    this->modelMat = glm::rotate(this->modelMat, glm::radians(angle), location);
}

void Sprite::scale(glm::vec3 ratio) {
    this->modelMat = glm::scale(this->modelMat, ratio);
}
