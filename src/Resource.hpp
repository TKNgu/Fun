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
    const ShaderProgram& buildShaderProgram(std::string);
private:
    Resource();
    std::filesystem::path basePath = std::filesystem::path("");
    std::map<std::filesystem::path, std::string> cacheText;
    std::map<std::filesystem::path, const Texture* const> cacheTexture;
    std::map<std::string, const ShaderProgram* const> cacheShaderProgram;
};

#endif // RESOURCE_HPP
