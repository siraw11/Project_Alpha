//
// Created by Luca Graziotti on 2019-06-19.
//

#include "GameEngine.h"

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

GameEngine::GameEngine(b2Vec2 _gravity, sf::VideoMode _video,int _framerate):gravity(_gravity),video(_video),framerate(_framerate) {}

void GameEngine::run() {
    sf::Window window(video, "Motocross 2D",sf::Style::Default);
    window.setFramerateLimit(framerate);
    while (window.isOpen()) {
        sf::Event Event;
        while (window.pollEvent(Event)) {
            if (Event.type == sf::Event::Closed)
                window.close();
        }
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
