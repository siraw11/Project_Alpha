//
// Created by Luca Graziotti on 2019-06-19.
//

#ifndef MOTOCROSS2D_GAMEENGINE_H
#define MOTOCROSS2D_GAMEENGINE_H


#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"
#include "Map.h"
#include "Item.h"


class GameEngine {
public:
    GameEngine(b2Vec2 gravity = b2Vec2(0.0f, 30),
               int framerate = 60);


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

    bool isPause() const;

    void setPause(bool pause);

private:
    sf::RenderWindow *window;
    sf::View view;

    int framerate;
    float32 timeStep = 1.0f / 60.0f;
    int32 velocityIterations = 3;
    int32 positionIterations = 6;

    b2WheelJoint *wheelEngineL;
    b2WheelJoint *wheelEngineR;
    b2Vec2 gravity = b2Vec2(0, 9.8);
    b2World world = b2World(gravity);
    Map level = {};
    Bike bike = {};

    const float SCALE = 200.;
    const float WHEEL_SIZE = 0.23;
    float LINE{};
    bool pause{};

    static float degToGrad(float deg);

    void drawMap();

    void drawBike();

    void drawItem(Item *item);

    void initBike();

    void drawInterface();

    static bool checkCollision(float r1x, float r1y, float r1w, float r2x, float r2y, float r2w, float r2h);
};


#endif //MOTOCROSS2D_GAMEENGINE_H
