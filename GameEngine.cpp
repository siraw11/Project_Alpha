//
// Created by Luca Graziotti on 2019-06-19.
//

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

#include "GameEngine.h"
#include "Player.h"
#include "Map.h"
#include "Match.h"
#include "Player.h"
#include "Bike.h"


GameEngine::GameEngine(b2Vec2 _gravity, sf::VideoMode _video, int _framerate) : gravity(_gravity), video(_video),
                                                                                framerate(_framerate) {}

void GameEngine::run() {
    sf::RenderWindow window(video, "Motocross 2D", sf::Style::Default);//Create window withe default resolution
    window.setFramerateLimit(framerate);//Set framerate limit
    this->window = &window;
    LINE =(window.getSize().y/SCALE)/1.3+0.01;

    std::list<Position> level1Points = {
            {-1, 10},//back limit
            {0,  0},
            {3,  0},
            {8,  1},
            {8,  -1},
            {15, -1},
            {15, 10},//front limit
    };
    Map level1(false, true, 1, level1Points, nullptr);
    Map *level = &level1;

    Bike bike1("", "", 3, 0, 0, true, nullptr, nullptr);
    Bike *bike = &bike1;
    initBike(bike);


    while (window.isOpen()) {
        window.clear(sf::Color(255, 255, 255));//clear all,new frame!
        sf::Event event;


        world.Step(timeStep, velocityIterations, positionIterations);//calculate world simulation step


        //std::cout << "Speed:" << bike->wheelL->GetLinearVelocity().x << "  |  " << bike->wheelL->GetLinearVelocity().y << std::endl;
        //std::cout << "Position:" << bike.wheelL->GetPosition().x << "  |  " << bike.wheelL->GetPosition().y << std::endl;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered) {
                char keyPressed = static_cast<char>(event.text.unicode);
                std::cout << bike->getSpeed() << std::endl;
                switch (keyPressed) {
                    case 'd'://vai a destra
                        (bike->wheelL->SetLinearVelocity(b2Vec2(bike->wheelL->GetLinearVelocity().x + bike->getSpeed(),
                                                                bike->wheelL->GetLinearVelocity().y)));
                        break;
                    case 'a'://vai a sinistra
                        (bike->wheelL->SetLinearVelocity(b2Vec2(bike->wheelL->GetLinearVelocity().x - bike->getSpeed(),
                                                                bike->wheelL->GetLinearVelocity().y)));
                        break;
                    case char(32)://(spazio) freno
                        (bike->wheelL->SetLinearVelocity(b2Vec2(0, 0)));
                        break;
                    case 'w'://vai a su
                        (bike->wheelR->SetLinearVelocity(b2Vec2(bike->wheelR->GetLinearVelocity().x, -10)));
                        break;
                    case 's'://vai a giu
                        (bike->wheelL->SetLinearVelocity(b2Vec2(bike->wheelL->GetLinearVelocity().x, -10)));
                        break;
                }

            }
        }
        drawMap(level);
        drawBike(bike);

        window.display();
    }

}


float32 GameEngine::getTimeStep() const {
    return timeStep;
}

void GameEngine::setTimeStep(float32 timeStep) {
    GameEngine::timeStep = timeStep;
}

int32 GameEngine::getVelocityIterations() const {
    return velocityIterations;
}

void GameEngine::setVelocityIterations(int32 velocityIterations) {
    GameEngine::velocityIterations = velocityIterations;
}

int32 GameEngine::getPositionIterations() const {
    return positionIterations;
}

void GameEngine::setPositionIterations(int32 positionIterations) {
    GameEngine::positionIterations = positionIterations;
}

const b2Vec2 &GameEngine::getGravity() const {
    return gravity;
}

void GameEngine::setGravity(const b2Vec2 &gravity) {
    GameEngine::gravity = gravity;
}

const b2World &GameEngine::getWorld() const {
    return world;
}

void GameEngine::setWorld(const b2World &world) {
    GameEngine::world = world;
}

const sf::VideoMode &GameEngine::getVideo() const {
    return video;
}

void GameEngine::setVideo(const sf::VideoMode &video) {
    GameEngine::video = video;
}

int GameEngine::getFramerate() const {
    return framerate;
}

void GameEngine::setFramerate(int framerate) {
    GameEngine::framerate = framerate;
}



void GameEngine::drawMap(Map *level) {
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, LINE);//TODO:get dinamycally that value
    b2Body *groundBody = world.CreateBody(&groundBodyDef);

    //sf::VertexArray terrain;
    sf::VertexArray terrain(sf::TriangleStrip, level->getMapPoints().size() * 2);

    int i = 0;
    int j = 0;
    b2Vec2 vs[level->getMapPoints().size()];//box2D map points
    for (Position point : level->getMapPoints()) {
        //vs[i].Set(point.posX*SCALE, -point.posY*SCALE);
        vs[i].Set(point.posX, -point.posY);
        terrain[j].position = sf::Vector2f(point.posX * SCALE, window->getSize().y / 1.3 - (point.posY * SCALE));
        terrain[j].color = sf::Color(168, 75, 0);
        //aggiungo il corrispettivo negativo per disegnare il TriangleVertex
        //vedi:https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php
        j++;
        terrain[j].position = sf::Vector2f(point.posX * SCALE, 4000);
        terrain[j].color = sf::Color(168, 75, 0);
        //normal index increment
        j++;
        i++;
    }

    //Unisco tutti i punti con delle rette
    b2ChainShape chain;
    chain.CreateChain(vs, level->getMapPoints().size());
    groundBody->CreateFixture(&chain, 0.0f);//0.0f->mass of solid

    window->draw(terrain);
}

void GameEngine::initBike(Bike *bike) {
    /*
    b2BodyDef* bodyDef = new b2BodyDef();
    bodyDef->position.Set(0, 3.5);

    b2Body* cart = world.CreateBody(bodyDef);

    boxDef = new b2PolygonDef();
    boxDef.density = 2;
    boxDef.friction = 0.5;
    boxDef.restitution = 0.2;
    boxDef.filter.groupIndex = -1;

    boxDef.SetAsBox(1.5, 0.3);
    cart.CreateShape(boxDef);

    boxDef.SetAsOrientedBox(0.4, 0.15, new b2Vec2(-1, -0.3), Math.PI/3);
    cart.CreateShape(boxDef);

    boxDef.SetAsOrientedBox(0.4, 0.15, new b2Vec2(1, -0.3), -Math.PI/3);
    cart.CreateShape(boxDef);

    cart.SetMassFromShapes();

    boxDef.density = 1;
    */





    b2BodyDef wheelLDef;
    wheelLDef.type = b2_dynamicBody;
    wheelLDef.position.Set(1, LINE - WHEEL_SIZE);//initial position

    bike->wheelL = world.CreateBody(&wheelLDef);
    b2CircleShape dynamicWheel;
    dynamicWheel.m_p.Set(0, 0);
    dynamicWheel.m_radius = WHEEL_SIZE;
    //altre caratteristiche fisiche della ruota
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicWheel;
    fixtureDef.density = 10;
    fixtureDef.friction = 5;//attrito
    fixtureDef.restitution = 0;//rimbalzo
    bike->wheelL->CreateFixture(&fixtureDef);
    //disegno la ruota



    b2BodyDef wheelRDef;
    wheelRDef.type = b2_dynamicBody;
    wheelRDef.position.Set(2, LINE - WHEEL_SIZE);//initial position


    bike->wheelR = world.CreateBody(&wheelRDef);

    //creo la ruota come sfera(sempre Box2D)
    b2CircleShape dynamicWheelR;
    dynamicWheelR.m_p.Set(0, 0);
    dynamicWheelR.m_radius = WHEEL_SIZE;
    //altre caratteristiche fisiche della ruota
    b2FixtureDef fixtureDefR;
    fixtureDefR.shape = &dynamicWheelR;
    fixtureDefR.density = 10;
    fixtureDefR.friction = 5;//attrito
    fixtureDefR.restitution = 0;//rimbalzo
    bike->wheelR->CreateFixture(&fixtureDefR);
    //disegno la ruota


    b2DistanceJointDef jointDef;
    jointDef.Initialize(bike->wheelL, bike->wheelR, bike->wheelL->GetLocalCenter(), bike->wheelL->GetLocalCenter());
    jointDef.collideConnected = true;
    jointDef.bodyA = bike->wheelL;
    jointDef.bodyB = bike->wheelR;
    jointDef.localAnchorA.Set(0, 0);
    jointDef.localAnchorB.Set(0, 0);
    jointDef.length = 0.7;
    world.CreateJoint(&jointDef);

}

void GameEngine::drawBike(Bike *bike) {
    sf::Texture texture;
    if (!texture.loadFromFile("../textures/wheel.png"))
        std::cout << "Cannot load texture" << std::endl;
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::CircleShape wheelLDraw(WHEEL_SIZE * SCALE);
    wheelLDraw.setFillColor(sf::Color(255, 187, 0));
    wheelLDraw.setTexture(&texture);


    sf::CircleShape wheelRDraw(WHEEL_SIZE * SCALE);
    wheelRDraw.setFillColor(sf::Color(255, 187, 0));
    wheelRDraw.setTexture(&texture);


    b2Vec2 positionL = bike->wheelL->GetPosition();//new position of the body
    float32 angleL = bike->wheelL->GetAngle();
    b2Vec2 speedL = bike->wheelL->GetLinearVelocity();

    b2Vec2 positionR = bike->wheelR->GetPosition();//new position of the body
    float32 angleR = bike->wheelR->GetAngle();
    b2Vec2 speedR = bike->wheelR->GetLinearVelocity();


    wheelLDraw.setPosition(positionL.x * SCALE, positionL.y * SCALE);
    wheelRDraw.setPosition(positionR.x * SCALE, positionR.y * SCALE);

    float origin = WHEEL_SIZE * SCALE;

    wheelLDraw.setOrigin(origin, origin);
    wheelRDraw.setOrigin(origin, origin);

    wheelLDraw.rotate(angleL * SCALE / 2);
    wheelRDraw.rotate(angleR * SCALE / 2);


    window->draw(wheelLDraw);
    window->draw(wheelRDraw);
}