#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <string>
#include <filesystem>
#include <map>
#include "Texture.hpp"
#include "ShaderProgram.hpp"

class Resource {
public:
    static Resource& getInstance();
    ~Resource();
    Resource& setPath(std::filesystem::path);
    const std::string& loadText(std::filesystem::path);
    const Texture& loadTexture(std::filesystem::path);
private:
    Resource();
    std::string loadFileText(std::filesystem::path);
    std::filesystem::path basePath = std::filesystem::path("");
    std::map<std::filesystem::path, std::string> cacheText;
    std::map<std::filesystem::path, const Texture* const> cacheTexture;
};

#endif // RESOURCE_HPP
