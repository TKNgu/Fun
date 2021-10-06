#include "Resource.hpp"

#include <fstream>
#include <filesystem>
#include <stdexcept>
#include <sstream>
#include <iostream>

#include "OpenGLUtility.hpp"

using namespace std;
using namespace std::filesystem;

Resource& Resource::getInstance() {
    static Resource instance;
    return instance;
}

Resource::~Resource() {
    for (auto& item : this->cacheTexture) {
        delete item.second;
    }
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
        this->cacheText[filePath] = loadFileText(fullFilePath);
    }
    return this->cacheText[filePath];
}

const Texture& Resource::loadTexture(path filePath) {
    auto fullFilePath = this->basePath / filePath;
    if (this->cacheTexture.find(filePath) == this->cacheTexture.end()) {
        auto texture = new const Texture(fullFilePath);
        this->cacheTexture.insert({ filePath, texture });
    }
    return *this->cacheTexture[filePath];
}

string Resource::loadFileText(filesystem::path filePath) {
    ifstream file(filePath);
    file.exceptions(ifstream::failbit | ifstream::badbit);
    if (!file.is_open()){
        throw runtime_error("Error open file " + filePath.string());
    }
    stringstream strStream;
    strStream << file.rdbuf();
    file.close();
    return strStream.str();
}
