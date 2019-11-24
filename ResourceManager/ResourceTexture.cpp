//
// Created by Luca Graziotti on 24/11/2019.
//

#include "ResourceTexture.h"

ResourceTexture::ResourceTexture(const std::string &name, const std::string &filePath) : Resource(name, filePath) {
    sf::Texture _texture;
    if (_texture.loadFromFile(this->getFilePath())) {
        this->texture = _texture;
    } else {
        throw ResourceManagerException("Texture " + this->getName() + " not found at: " + this->getFilePath());
    }
}

ResourceTexture::~ResourceTexture() {

}

const sf::Texture &ResourceTexture::getTexture() const {
    return texture;
}

void ResourceTexture::setTexture(const sf::Texture &texture) {
    ResourceTexture::texture = texture;
}
