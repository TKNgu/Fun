#include "Texture.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include <glad/glad.h>
#include <stdexcept>
#include <string>
#include <iostream>

using namespace std;
using namespace std::filesystem;

Texture::Texture(path filePath) {
    cout << "File" << endl;
    auto data = stbi_load(filePath.c_str(),
                          &this->width, &this->height, &this->nrChannels, 0);
    if (!data) {
        throw runtime_error("Error open file " + filePath.string());
    }
    glGenTextures(1, &this->texture);
    glBindTexture(GL_TEXTURE_2D, this->texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, this->nrChannels, this->width, this->height,
                 0, this->nrChannels, GL_UNSIGNED_BYTE, data);
    stbi_image_free(data);
}

Texture::Texture(const Texture& texture) :
    width(texture.width), height(texture.height), nrChannels(texture.nrChannels), texture(texture.texture) {
    cout << "Copy" << endl;
}

Texture::Texture(const Texture&& texture) {
    cout << "Clone" << endl;
}

Texture::Texture() {
    cout << "Empty" << endl;
}

Texture::~Texture() {
    cout << "Destroy" << endl;
    glDeleteTextures(1, &this->texture);
}

Texture& Texture::operator = (const Texture& texture) {
    cout << "=" << endl;
    this->width = texture.texture;
    this->height = texture.height;
    this->nrChannels = texture.nrChannels;
    return *this;
}
