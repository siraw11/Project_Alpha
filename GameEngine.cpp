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
    window.setFramerateLimit(framerate);//Set framerate limit


    std::list<Position> level1Points = {{0,  0},
                                        {3,  0},
                                        {5,  -0.3},
                                        {8,  0},
                                        {10, 1},
                                        {15, 1}};
    Map level1(false, true, 1, level1Points, this, nullptr);
    Bike bike("","",10,0,0,true,this, nullptr, nullptr);

    while (window.isOpen()) {
        window.clear(sf::Color(255, 255, 255));//clear all,new frame!
        sf::Event event;


        world.Step(timeStep, velocityIterations, positionIterations);//calculate world simulation step




        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
            if (event.type == sf::Event::TextEntered) {
                char keyPressed = static_cast<char>(event.text.unicode);


                switch (keyPressed) {
                    case 'd'://vai a destra

                        (bike.wheelL->SetLinearVelocity(b2Vec2(bike.wheelL->GetLinearVelocity().x + 200.f, bike.wheelL->GetLinearVelocity().y)));

                        (bike.wheelR->SetLinearVelocity(b2Vec2(bike.wheelL->GetLinearVelocity().x + 200.f, bike.wheelR->GetLinearVelocity().y)));
                        std::cout <<bike.wheelL->GetLinearVelocity().x  << "----" <<bike.wheelR->GetLinearVelocity().x << std::endl;

                        break;
                    case 'a'://vai a sinistra
                        (bike.wheelL->SetLinearVelocity(b2Vec2(bike.wheelL->GetLinearVelocity().x - 200, bike.wheelL->GetLinearVelocity().y)));
                        (bike.wheelR->SetLinearVelocity(b2Vec2(bike.wheelR->GetLinearVelocity().x - 200, bike.wheelR->GetLinearVelocity().y)));

                        break;
                    case char(32)://(spazio) freno
                        (bike.wheelL->SetLinearVelocity(b2Vec2(bike.wheelL->GetLinearVelocity().x, -30)));
                        break;
                }

            }
        }
        level1.draw(&window);
        bike.draw(&window);

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
