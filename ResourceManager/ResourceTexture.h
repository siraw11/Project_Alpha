//
// Created by Luca Graziotti on 24/11/2019.
//

#ifndef MOTOCROSS2D_RESOURCETEXTURE_H
#define MOTOCROSS2D_RESOURCETEXTURE_H


#include <string>
#include <SFML/Graphics/Texture.hpp>
#include "Resource.h"

class ResourceTexture : public Resource {
private:
    sf::Texture texture;
public:

    const sf::Texture &getTexture() const;

    void setTexture(const sf::Texture &texture);

    virtual ~ResourceTexture();

    ResourceTexture(const std::string &name, const std::string &filePath);

};


#endif //MOTOCROSS2D_RESOURCETEXTURE_H
