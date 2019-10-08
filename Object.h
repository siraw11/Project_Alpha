
#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include <SFML/Graphics.hpp>

//Classe base per tutti gli oggetti di gioco

class Object {
public:

    sf::RectangleShape rectShape;//HitBox

public:

    void init(float x, float y, sf::Vector2f size);//Setta lo spawn e le dimensioni dell'oggetto
    virtual void setTexture(const std::string &textureDir);//Setta la texture
public:
    //Parametri posizione e hitbox
    float x, y, spawnX, spawnY;
    float hitTop, hitBottom, hitLeft, hitRight;
    float width, height;
protected:

    sf::Texture rectTexture;

};


#endif
