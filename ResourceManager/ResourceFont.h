//
// Created by Luca Graziotti on 24/11/2019.
//

#ifndef MOTOCROSS2D_RESOURCEFONT_H
#define MOTOCROSS2D_RESOURCEFONT_H

#include <string>
#include <SFML/Graphics/Font.hpp>
#include "Resource.h"

class ResourceFont : public Resource {
private:
    sf::Font font;
public:
    ResourceFont(const std::string &name, const std::string &filePath);

    const sf::Font &getFont() const;

    void setFont(const sf::Font &font);

    virtual ~ResourceFont();
};


#endif //MOTOCROSS2D_RESOURCEFONT_H
