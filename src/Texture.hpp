#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <filesystem>

class Texture {
public:
    Texture(std::filesystem::path);
    Texture(const Texture&);
    Texture(const Texture&&);
    Texture();
    ~Texture();
    Texture& operator = (const Texture&);
private:
    int width;
    int height;
    int nrChannels;
    unsigned int texture;
};

#endif // TEXTURE_HPP
