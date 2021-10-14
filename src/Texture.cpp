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
    stbi_set_flip_vertically_on_load(true);
    auto data = stbi_load(filePath.string().c_str(),
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

    switch (nrChannels) {
    case 3: {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->width, this->height,
            0, GL_RGB, GL_UNSIGNED_BYTE, data);
        break;
    }
    case 4: {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, this->width, this->height,
            0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        break;
    }
    default: {
        stbi_image_free(data);
        throw runtime_error("Image format not support");
    }
    }
    stbi_image_free(data);
}

Texture::~Texture() {
    glDeleteTextures(1, &this->texture);
}

void Texture::bind() const {
    glBindTexture(GL_TEXTURE_2D, this->texture);
}
