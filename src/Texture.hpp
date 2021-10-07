#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <filesystem>

class Texture {
public:
    Texture(std::filesystem::path);
    ~Texture();
    void bind() const;
private:
    int width;
    int height;
    int nrChannels;
    unsigned int texture;
};

#endif // TEXTURE_HPP
