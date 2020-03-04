
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>

//Classe base per tutti gli oggetti di gioco

class RectangleShape {
public:
    virtual ~RectangleShape();

    void init(float x, float y, sf::Vector2f size);//Setta lo spawn e le dimensioni dell'oggetto
    virtual void setTexture(const std::string &textureDir);//Setta la texture

    sf::RectangleShape rectShape;//HitBox
    //Parametri posizione e hitbox
    float x, y, spawnX, spawnY;
    float hitTop, hitBottom, hitLeft, hitRight;
    float width, height;

protected:
    sf::Texture rectTexture;
};


#endif
