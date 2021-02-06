//
// Created by Luca Graziotti on 24/11/2019.
//

#include "ResourceFont.h"


ResourceFont::ResourceFont(const std::string &name, const std::string &filePath) : Resource(name, filePath) {
    sf::Font _font;
    if (_font.loadFromFile(this->getFilePath())) {
        this->font = _font;
    } else {
        throw ResourceManagerException("Font " + this->getName() + " not found at: " + this->getFilePath());
    }
}


ResourceFont::~ResourceFont() {

}

const sf::Font &ResourceFont::getFont() const {
    return font;
}

void ResourceFont::setFont(const sf::Font &font) {
    ResourceFont::font = font;
}
