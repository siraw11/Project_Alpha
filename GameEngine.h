//
// Created by Luca Graziotti on 2019-06-19.
//

#ifndef MOTOCROSS2D_GAMEENGINE_H
#define MOTOCROSS2D_GAMEENGINE_H


#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include "Map.h"

class GameEngine {
public:
    GameEngine(b2Vec2 gravity = b2Vec2(0.0f, 30), sf::VideoMode video = sf::VideoMode::getDesktopMode(),int framerate = 60);
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 3;
    int32 positionIterations = 6;
    b2Vec2 gravity;
    b2World world = b2World(gravity);
    int framerate;
    sf::VideoMode video;
    sf::RenderWindow * window;
    const float SCALE = 200.f;
    const float WHEEL_SIZE = 0.23;
    float LINE;



    void run();

    float32 getTimeStep() const;

    int getFramerate() const;

    void setFramerate(int framerate);

    void setTimeStep(float32 timeStep);

    int32 getVelocityIterations() const;

    void setVelocityIterations(int32 velocityIterations);

    int32 getPositionIterations() const;

    void setPositionIterations(int32 positionIterations);

    const b2Vec2 &getGravity() const;

    void setGravity(const b2Vec2 &gravity);

    const b2World &getWorld() const;

    void setWorld(const b2World &world);

    const sf::VideoMode &getVideo() const;

    void setVideo(const sf::VideoMode &video);

    void drawMap(Map * level);

    void drawBike(Bike * bike);

    void initBike(Bike * bike);


private:
    float degToGrad(float deg);
};


#endif //MOTOCROSS2D_GAMEENGINE_H
