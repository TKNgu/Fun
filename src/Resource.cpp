#include "Resource.hpp"

#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <sstream>
#include <iostream>

using namespace std;
using namespace std::filesystem;

Resource& Resource::getInstance() {
    static Resource instance;
    return instance;
}

Resource::Resource() {
    //TODO
}

Resource& Resource::setPath(path basePath) {
    this->basePath = basePath;
    return *this;
}

const string& Resource::loadText(path filePath) {
    auto fullFilePath = this->basePath / filePath;
    if (this->cacheText.find(filePath) == this->cacheText.end()) {
        ifstream file(fullFilePath.string());
        file.exceptions (ifstream::failbit | ifstream::badbit);
        if (!file.is_open()) {
            throw runtime_error("Error open file " + fullFilePath.string());
        }
        stringstream strStream;
        strStream << file.rdbuf();
        file.close();
        this->cacheText[filePath] = strStream.str();
    }
    return this->cacheText[filePath];
}

const Texture& Resource::loadTexture(path filePath) {
    auto fullFilePath = this->basePath / filePath;
    if (this->cacheTexture.find(filePath) == this->cacheTexture.end()) {
        Texture texture(fullFilePath);
        this->cacheTexture[filePath] = texture;
    }
    return this->cacheTexture[filePath];
}
