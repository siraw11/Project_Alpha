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

float cartX = 0.8;
float cartY = 0.4;
b2WheelJoint* wheelJointL;
b2WheelJoint* wheelJointR;


GameEngine::GameEngine(b2Vec2 _gravity, sf::VideoMode _video, int _framerate) : gravity(_gravity), video(_video),
                                                                                framerate(_framerate) {}

void GameEngine::run() {
    sf::RenderWindow window(video, "Motocross 2D", sf::Style::Default);//Create window withe default resolution
    window.setFramerateLimit(framerate);//Imposto framerate limit
    this->window = &window;

    LINE = (window.getSize().y / SCALE) / 1.3 + 0.01;

    sf::View view;
    view.reset(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y));
    window.setView(view);

    std::list<Position> level1Points = {
            {-1, 10},//back limit
            {0,  0},
            {3,  0},
            {8,  1},
            {11, 0},
            {15, -1},
            {20, 0},
            {25, 0},
            {30, 0.5},
            {35, -2},
            {40, 0},
            {43, 0},
            {45, 1},
            {55, 1},
            {55, 10}//front limit
    };


    std::list<Position> level2Points = {
            {-1, 10},//back limit
            {0,  0},
            {1000, 0},
            {1000, 10}//front limit
    };



    Map level1(false, true, 1, level1Points, nullptr);
    Map level2(false, true, 1, level2Points, nullptr);


    Map *level = &level1;

    Bike bike1("", "", 50, 0, 0, true, nullptr, nullptr, nullptr);
    Bike *bike = &bike1;
    initBike(bike);

    while (window.isOpen()) {
        window.clear(sf::Color(255, 255, 255));//ripulisco nuovo frame
        sf::Event event;


        world.Step(timeStep, velocityIterations, positionIterations);


        float offsetX = 3;
        float offsetY = 1;
        if (((bike->wheelL->GetPosition().x + offsetX) * SCALE) >
            (window.getSize().x / 2)) {     //camera start moving when bike is in the center
            view.setCenter((bike->wheelL->GetPosition().x + offsetX) * SCALE,
                           (bike->wheelL->GetPosition().y - offsetY) * SCALE); //camera moving on bike
            window.setView(view);
        }


        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

            wheelJointL->SetMotorSpeed(0);
            wheelJointR->SetMotorSpeed(0);
            if (event.type == sf::Event::TextEntered) {
                char keyPressed = static_cast<char>(event.text.unicode);
                float speed;

                switch (keyPressed) {
                    case 'd'://right
                            wheelJointL->SetMotorSpeed(speed+ bike->getSpeed());
                            wheelJointR->SetMotorSpeed(speed+ bike->getSpeed());
                        break;
                    case 'a'://left
                            speed = wheelJointL->GetMotorSpeed();
                            wheelJointL->SetMotorSpeed(-(abs(speed)+ bike->getSpeed()));
                            wheelJointR->SetMotorSpeed(-(abs(speed)+ bike->getSpeed()));
                        break;
                    case char(32)://hard brake
                            wheelJointL->SetMotorSpeed(0);
                            wheelJointR->SetMotorSpeed(0);
                        break;
                    case 'w'://vai a su
                        (bike->wheelR->SetLinearVelocity(b2Vec2(bike->wheelR->GetLinearVelocity().x, -5)));
                        break;
                    case 's'://vai a giu
                        (bike->wheelL->SetLinearVelocity(b2Vec2(bike->wheelL->GetLinearVelocity().x, -5)));
                        break;

                    case 'r'://vai a giu
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
    groundBodyDef.position.Set(0, LINE);
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

    /*----------------------------------------
     * Definizione Cart Moto
     */
    //Definizione oggetto fisico del Cart
    b2PolygonShape cartShape;
    cartShape.SetAsBox(cartX, cartY);
    b2BodyDef cartBodyDef;
    cartBodyDef.type = b2_dynamicBody;
    cartBodyDef.position.Set(1, LINE - cartY - WHEEL_SIZE ); //posizione iniziale

    //Definizione caratteristiche fisiche
    b2FixtureDef cartFixtureDef;
    cartFixtureDef.shape = &cartShape;
    cartFixtureDef.density = 2;
    cartFixtureDef.friction = 0.5;
    cartFixtureDef.restitution = 0.2;
    cartFixtureDef.filter.groupIndex = 1;

    //Inizializzazione Cart
    bike->cart = world.CreateBody(&cartBodyDef);
    bike->cart->CreateFixture(&cartFixtureDef);


    /*----------------------------------------
     * Definizione Ruote Moto
     */

    //Definizione oggetto fisico delle ruote
    b2CircleShape dynamicWheel;
    dynamicWheel.m_p.Set(0, 0);
    dynamicWheel.m_radius = WHEEL_SIZE;
    b2BodyDef wheelDef;
    wheelDef.type = b2_dynamicBody;

    //Definizione caratteristiche fisiche delle ruote
    b2FixtureDef wheelFixtureDef;
    wheelFixtureDef.shape = &dynamicWheel;
    wheelFixtureDef.density = 10;
    wheelFixtureDef.friction = 5;//attrito
    wheelFixtureDef.restitution = 0;//rimbalzo
    //wheelFixtureDef.filter.groupIndex = -1;

    //Inizializzazione ruota sinistra
    wheelDef.position.Set(1, LINE - WHEEL_SIZE);//Posizione iniziale ruota sinistra
    bike->wheelL = world.CreateBody(&wheelDef);
    bike->wheelL->CreateFixture(&wheelFixtureDef);

    //Inizializzazione ruota destra
    wheelDef.position.Set(3, LINE - WHEEL_SIZE);//Posizione iniziale ruota destra
    bike->wheelR = world.CreateBody(&wheelDef);
    bike->wheelR->CreateFixture(&wheelFixtureDef);


    /*
     * Definizione Joints Moto
     */

    //Distance joint per connettere la ruota destra e quella sinistra
    b2DistanceJointDef dJointDefR_L;
    dJointDefR_L.Initialize(bike->wheelL, bike->wheelR,b2Vec2(0,0),b2Vec2(0,0));
    dJointDefR_L.collideConnected = false;
    dJointDefR_L.localAnchorA.Set(0, 0);
    dJointDefR_L.localAnchorB.Set(0, 0);
    dJointDefR_L.length = .95;
    world.CreateJoint(&dJointDefR_L);



    //Definizione Caratteristiche Wheel Joint
    b2WheelJointDef wheelJointDef;
    wheelJointDef.bodyA = bike->cart;
    wheelJointDef.localAnchorB.Set(0,0);
    wheelJointDef.enableMotor = true;
    wheelJointDef.maxMotorTorque = 10;
    wheelJointDef.motorSpeed = 0;
    wheelJointDef.dampingRatio = 1.0;

    //Inizializzazione Wheel Joint ruota sinistra
    wheelJointDef.bodyB = bike->wheelL;
    wheelJointDef.localAnchorA.Set(-125*1/SCALE,50*1/SCALE);
    wheelJointL = (b2WheelJoint*)world.CreateJoint(&wheelJointDef);


    //Inizializzazione Wheel Joint ruota destra
    wheelJointDef.bodyB = bike->wheelR;
    wheelJointDef.localAnchorA.Set(125*1/SCALE,50*1/SCALE);
    wheelJointR = (b2WheelJoint*)world.CreateJoint(&wheelJointDef);
}

void GameEngine::drawBike(Bike *bike) {
    //Caricamento sprite Ruote moto
    sf::Texture wheelTexture;
    bool wheelTextureFound = wheelTexture.loadFromFile("../textures/wheel.png");
    if (!wheelTextureFound)
        std::cout << "Impossibile caricare texture Ruote - Moto" << std::endl;
    sf::Sprite spriteWheel;
    spriteWheel.setTexture(wheelTexture);
    //-----------------------

    //Caricamento sprite Cart moto
    sf::Texture cartTexture;
    bool cartTextureFound = cartTexture.loadFromFile("../textures/cart.png");
    if (!cartTextureFound)
        std::cout << "Impossibile caricare texture Cart - Moto" << std::endl;
    sf::Sprite cartSprite;
    cartSprite.setTexture(cartTexture);
    //------------------------


    //Disegno ruota sinistra con sprite
    sf::CircleShape wheelLDraw(WHEEL_SIZE * SCALE);
    wheelLDraw.setFillColor(sf::Color(255, 187, 0));
    wheelLDraw.setTexture(&wheelTexture);


    //Disegno ruota destra con sprite
    sf::CircleShape wheelRDraw(WHEEL_SIZE * SCALE);
    wheelRDraw.setFillColor(sf::Color(255, 187, 0));
    wheelRDraw.setTexture(&wheelTexture);

    //Disegno cart con sprite
    sf::RectangleShape cartDraw(sf::Vector2f(cartX * 2 * SCALE, cartY * 3 * SCALE));
    cartDraw.setFillColor(sf::Color(255, 187, 0));
    cartDraw.setTexture(&cartTexture);


    //Ricavo nuovi dati fisici ruota sinistra
    b2Vec2 positionWheelL = bike->wheelL->GetPosition();     //posizione
    float32 angleWheelL = bike->wheelL->GetAngle();          //angolo
    b2Vec2 speedWheelL = bike->wheelL->GetLinearVelocity();  //velocità

    //Ricavo nuovi dati fisici ruota destra
    b2Vec2 positionWheelR = bike->wheelR->GetPosition();     //posizione
    float32 angleWheelR = bike->wheelR->GetAngle();          //angolo
    b2Vec2 speedWheelR = bike->wheelR->GetLinearVelocity();  //velocità


    //Ricavo nuovi dati fisici cart
    b2Vec2 positionCart = bike->cart->GetPosition();     //posizione
    float32 angleCart = bike->cart->GetAngle();          //angolo
    b2Vec2 speedCart = bike->cart->GetLinearVelocity();  //velocità



    float speed = wheelJointL->GetMotorSpeed();
    //std::cout << speed << std::endl;


    float origin = WHEEL_SIZE * SCALE;
    wheelLDraw.setOrigin(origin, origin);
    wheelRDraw.setOrigin(origin, origin);
    cartDraw.setOrigin(cartX * SCALE, cartY * SCALE);


    //Aggiorno la posizione degli oggetti disegnati
    wheelLDraw.setPosition(positionWheelL.x * SCALE, positionWheelL.y * SCALE);
    wheelRDraw.setPosition(positionWheelR.x * SCALE, positionWheelR.y * SCALE);
    cartDraw.setPosition(positionCart.x * SCALE, (positionCart.y - cartY) * SCALE);


    //Aggiorno la rotazione degli oggetti disegnati
    wheelLDraw.rotate(degToGrad(angleWheelL));
    wheelRDraw.rotate(degToGrad(angleWheelR));
    cartDraw.rotate(degToGrad(angleCart));



    //Disegno gli oggetti
    window->draw(cartDraw);
    window->draw(wheelLDraw);
    window->draw(wheelRDraw);
}


//Conversione Radianti -> Gradi
float GameEngine::degToGrad(float deg) {
    return deg*(180/M_PI);
}