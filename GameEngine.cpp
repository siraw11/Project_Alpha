//
// Created by Luca Graziotti on 2019-06-19.
//

#include "GameEngine.h"
#include "Player.h"
#include "Map.h"
#include "Match.h"
#include "Player.h"
#include "Bike.h"

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

const float SCALE = 200.f;

GameEngine::GameEngine(b2Vec2 _gravity, sf::VideoMode _video, int _framerate) : gravity(_gravity), video(_video),
                                                                                framerate(_framerate) {}

void GameEngine::run() {
    sf::RenderWindow window(video, "Motocross 2D", sf::Style::Default);//Create window withe default resolution
    window.setFramerateLimit(240);//Set framerate limit


    std::list<Position> level1Points = {{0,  0},
                                        {3,  0},
                                        {5,  -0.3},
                                        {8,  0},
                                        {10, 1},
                                        {15, 1}};
    Map level1(false, true, 1, level1Points, &world, nullptr);


    //TODO MOVE WHEELS TO BIKE CLASS
    float wheelSize = 0.2;
    sf::Texture texture;
    if(!texture.loadFromFile("../textures/wheel.png"))
        std::cout << "Cannot load texture"<< std::endl;
    sf::Sprite sprite;
    sprite.setTexture(texture);



    b2BodyDef wheelLDef;
    wheelLDef.type = b2_dynamicBody;
    wheelLDef.position.Set(150.f, window.getSize().y/1.7);//initial position
    b2Body *wheelL = world.CreateBody(&wheelLDef);
    //creo la palla come sfera(sempre Box2D)
    b2CircleShape dynamicWheel;
    dynamicWheel.m_p.Set(0, 0);
    dynamicWheel.m_radius = wheelSize*SCALE;
    //altre caratteristiche fisiche della palla
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicWheel;
    fixtureDef.density = 1.f;
    fixtureDef.friction = 0.3f;//attrito
    fixtureDef.restitution = 0.5f;//rimbalzo
    wheelL->CreateFixture(&fixtureDef);
    //disegno la palla
    sf::CircleShape wheelLDraw(wheelSize* SCALE);
    wheelLDraw.setFillColor(sf::Color(255, 187, 0));
    wheelLDraw.setTexture(&texture);


    b2BodyDef wheelRDef;
    wheelRDef.type = b2_dynamicBody;
    wheelRDef.position.Set(300.f, window.getSize().y/1.7);//initial position
    b2Body *wheelR = world.CreateBody(&wheelRDef);
    //creo la palla come sfera(sempre Box2D)
    b2CircleShape dynamicWheelR;
    dynamicWheelR.m_p.Set(0, 0);
    dynamicWheelR.m_radius = wheelSize*SCALE;
    //altre caratteristiche fisiche della palla
    b2FixtureDef fixtureDefR;
    fixtureDefR.shape = &dynamicWheelR;
    fixtureDefR.density = 1.f;
    fixtureDefR.friction = 0.3f;//attrito
    fixtureDefR.restitution = 0.5f;//rimbalzo
    wheelR->CreateFixture(&fixtureDefR);
    //disegno la palla

    sf::CircleShape wheelRDraw(wheelSize* SCALE);
    wheelRDraw.setFillColor(sf::Color(255, 187, 0));
    wheelRDraw.setTexture(&texture);



    b2DistanceJointDef jointDef;
    jointDef.Initialize(wheelL, wheelR, wheelL->GetLocalCenter(), wheelL->GetLocalCenter()); jointDef.collideConnected = true;
    jointDef.bodyA = wheelL;
    jointDef.bodyB = wheelR;
    jointDef.localAnchorA.Set(2,2);
    jointDef.localAnchorB.Set(0,0);
    jointDef.length = 125;
    world.CreateJoint(&jointDef);

    while (window.isOpen()) {
        window.clear(sf::Color(255, 255, 255));//clear all,new frame!
        sf::Event event;


        world.Step(timeStep, velocityIterations, positionIterations);//calculate world simulation step
        b2Vec2 positionL = wheelL->GetPosition();//new position of the body
        float32 angleL = wheelL->GetAngle();
        b2Vec2 speedL = wheelL->GetLinearVelocity();

        b2Vec2 positionR = wheelR->GetPosition();//new position of the body
        float32 angleR = wheelR->GetAngle();
        b2Vec2 speedR = wheelR->GetLinearVelocity();

        wheelLDraw.setPosition(positionL.x-(wheelSize* SCALE), positionL.y-(wheelSize* SCALE));
        wheelRDraw.setPosition(positionR.x-(wheelSize* SCALE), positionR.y-(wheelSize* SCALE));
        //FIXME:rotation
        //wheelLDraw.rotate(angleL);
        //wheelRDraw.rotate(angleR);

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered) {
                char keyPressed = static_cast<char>(event.text.unicode);
                switch (keyPressed) {
                    case 'd'://vai a destra
                        (wheelL->SetLinearVelocity(b2Vec2(wheelL->GetLinearVelocity().x + 100, wheelL->GetLinearVelocity().y)));
                        (wheelR->SetLinearVelocity(b2Vec2(wheelR->GetLinearVelocity().x + 100, wheelR->GetLinearVelocity().y)));
                        break;
                    case 'a'://vai a sinistra
                        (wheelL->SetLinearVelocity(b2Vec2(wheelL->GetLinearVelocity().x - 100, wheelL->GetLinearVelocity().y)));
                        (wheelR->SetLinearVelocity(b2Vec2(wheelR->GetLinearVelocity().x - 100, wheelR->GetLinearVelocity().y)));
                        break;
                    case char(32)://(spazio) salta
                        (wheelL->SetLinearVelocity(b2Vec2(wheelL->GetLinearVelocity().x, -30)));
                        break;
                }
            }
        }
        level1.draw(&window);

        window.draw(wheelLDraw);
        window.draw(wheelRDraw);
        
        window.display();//display frame
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
