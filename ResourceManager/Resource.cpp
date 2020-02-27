//
// Created by Luca Graziotti on 24/11/2019.
//

#include <SFML/Graphics/Texture.hpp>
#include "Resource.h"

Resource::Resource(const std::string &name, const std::string &filePath) : name(name), filePath(filePath) {

}

Resource::~Resource() {

}

const std::string &Resource::getName() const {
    return this->name;
}

void Resource::setName(const std::string &_name) {
    this->name = _name;
}

const std::string &Resource::getFilePath() const {
    return this->filePath;
}

void Resource::setFilePath(const std::string &_filePath) {
    this->filePath = _filePath;
}
