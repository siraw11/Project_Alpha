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
    window.setFramerateLimit(framerate);//Set framerate limit
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

    Bike bike1("", "", 20, 0, 0, true, nullptr, nullptr, nullptr);
    Bike *bike = &bike1;
    initBike(bike);

    while (window.isOpen()) {
        window.clear(sf::Color(255, 255, 255));//clear all,new frame!
        sf::Event event;


        world.Step(timeStep, velocityIterations, positionIterations);//calculate world simulation step


        float offsetX = 3;
        float offsetY = 1;
        if (((bike->wheelL->GetPosition().x + offsetX) * SCALE) >
            (window.getSize().x / 2)) {     //camera start moving when bike is in the center
            view.setCenter((bike->wheelL->GetPosition().x + offsetX) * SCALE,
                           (bike->wheelL->GetPosition().y - offsetY) * SCALE); //camera moving on bike
            window.setView(view);
        }



        //std::cout << "Speed:" << bike->wheelL->GetLinearVelocity().x << "  |  " << bike->wheelL->GetLinearVelocity().y << std::endl;
        //std::cout << "Position:" << bike.wheelL->GetPosition().x << "  |  " << bike.wheelL->GetPosition().y << std::endl;

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::TextEntered) {
                char keyPressed = static_cast<char>(event.text.unicode);
                float speed;

                switch (keyPressed) {
                    case 'd'://right
                        speed = wheelJointL->GetMotorSpeed();
                        if(speed>=0&&speed<=200){
                            wheelJointL->SetMotorSpeed(speed+ bike->getSpeed());
                            wheelJointR->SetMotorSpeed(speed+ bike->getSpeed());
                        }else{
                            if(speed<-0.2){
                                wheelJointL->SetMotorSpeed(speed/2);
                                wheelJointR->SetMotorSpeed(speed/2);
                            }else if(speed>200){

                            }else{
                                wheelJointL->SetMotorSpeed(0);
                                wheelJointR->SetMotorSpeed(0);
                            }
                        }
                        break;
                    case 'a'://left
                        speed = wheelJointL->GetMotorSpeed();
                        if(speed>0){//frenata post accellerazione
                            if(speed>0.2){
                                wheelJointL->SetMotorSpeed(speed/2);
                                wheelJointR->SetMotorSpeed(speed/2);
                            }else{
                                wheelJointL->SetMotorSpeed(0);
                                wheelJointR->SetMotorSpeed(0);
                            }
                        }else{//retromarcia
                            wheelJointL->SetMotorSpeed(-(abs(speed)+ bike->getSpeed()));
                            wheelJointR->SetMotorSpeed(-(abs(speed)+ bike->getSpeed()));
                        }
                        break;
                    case char(32)://hard brake
                        wheelJointL->SetMotorSpeed(0);
                        wheelJointR->SetMotorSpeed(0);
                        break;
                    case 'w'://vai a su
                        (bike->wheelR->SetLinearVelocity(b2Vec2(bike->wheelR->GetLinearVelocity().x, -10)));
                        break;
                    case 's'://vai a giu
                        (bike->wheelL->SetLinearVelocity(b2Vec2(bike->wheelL->GetLinearVelocity().x, -10)));
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

    b2BodyDef cartBodyDef;

    cartBodyDef.type = b2_dynamicBody; //this will be a dynamic body
    cartBodyDef.position.Set(1, LINE - cartY - WHEEL_SIZE ); //set the starting position

    bike->cart = world.CreateBody(&cartBodyDef);
    b2PolygonShape cartShape;
    cartShape.SetAsBox(cartX, cartY);
    b2FixtureDef cartFixtureDef;
    cartFixtureDef.shape = &cartShape;
    cartFixtureDef.density = 2;
    cartFixtureDef.friction = 0.5;
    cartFixtureDef.restitution = 0.2;
    cartFixtureDef.filter.groupIndex = 1;
    bike->cart->CreateFixture(&cartFixtureDef);



    b2BodyDef wheelLDef;
    wheelLDef.type = b2_dynamicBody;
    //wheelLDef.position.Set(1, LINE - WHEEL_SIZE);//initial position
    wheelLDef.position.Set(1, LINE - WHEEL_SIZE);//initial position

    bike->wheelL = world.CreateBody(&wheelLDef);
    b2CircleShape dynamicWheel;
    dynamicWheel.m_p.Set(0, 0);
    dynamicWheel.m_radius = WHEEL_SIZE;
    //altre caratteristiche fisiche della ruota
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicWheel;
    fixtureDef.density = 10;
    fixtureDef.friction = 50;//attrito
    fixtureDef.restitution = 0;//rimbalzo
    //fixtureDef.filter.groupIndex = -1;
    bike->wheelL->CreateFixture(&fixtureDef);
    //disegno la ruota



    b2BodyDef wheelRDef;
    wheelRDef.type = b2_dynamicBody;
    //wheelRDef.position.Set(2, LINE - WHEEL_SIZE);//initial position
    wheelRDef.position.Set(3, LINE - WHEEL_SIZE);//initial position


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
    //fixtureDefR.filter.groupIndex = -1;
    bike->wheelR->CreateFixture(&fixtureDefR);



    /*
     * Bike JOINTS
     */
    /*distance joint to connect the left wheel with the right wheel*/
    b2DistanceJointDef dJointDefR_L;
    dJointDefR_L.Initialize(bike->wheelL, bike->wheelR,b2Vec2(0,0),b2Vec2(0,0));
    dJointDefR_L.collideConnected = true;
    dJointDefR_L.localAnchorA.Set(0, 0);
    dJointDefR_L.localAnchorB.Set(0, 0);
    dJointDefR_L.length = .95;
    world.CreateJoint(&dJointDefR_L);



    //Left wheel joint
    b2WheelJointDef wheelJointDef;
    wheelJointDef.bodyA = bike->cart;
    wheelJointDef.bodyB = bike->wheelR;
    wheelJointDef.localAnchorA.Set(125*1/SCALE,50*1/SCALE);
    wheelJointDef.localAnchorB.Set(0,0);
    wheelJointDef.enableMotor = true;
    wheelJointDef.maxMotorTorque = 10;
    wheelJointDef.motorSpeed = 0;
    wheelJointDef.dampingRatio = 1.0;
    wheelJointR = (b2WheelJoint*)world.CreateJoint(&wheelJointDef);


    //Right wheel joint
    wheelJointDef.bodyB = bike->wheelL;
    wheelJointDef.localAnchorA.Set(-100*1/SCALE,50*1/SCALE);
    wheelJointL = (b2WheelJoint*)world.CreateJoint(&wheelJointDef);

    //---------------------------------
}

void GameEngine::drawBike(Bike *bike) {
    sf::Texture wheelTexture;
    if (!wheelTexture.loadFromFile("../textures/wheel.png"))
        std::cout << "Cannot load texture" << std::endl;
    sf::Sprite spriteWheel;
    spriteWheel.setTexture(wheelTexture);


    sf::Texture cartTexture;
    if (!cartTexture.loadFromFile("../textures/cart.png"))
        std::cout << "Cannot load texture" << std::endl;
    sf::Sprite cartSprite;
    cartSprite.setTexture(cartTexture);

    sf::CircleShape wheelLDraw(WHEEL_SIZE * SCALE);
    wheelLDraw.setFillColor(sf::Color(255, 187, 0));
    wheelLDraw.setTexture(&wheelTexture);


    sf::CircleShape wheelRDraw(WHEEL_SIZE * SCALE);
    wheelRDraw.setFillColor(sf::Color(255, 187, 0));
    wheelRDraw.setTexture(&wheelTexture);

    //sf::RectangleShape cartDraw(sf::Vector2f(cartX * 2 * SCALE, cartY * 4 * SCALE));
    sf::RectangleShape cartDraw(sf::Vector2f(cartX * 2 * SCALE, cartY * 3 * SCALE));
    cartDraw.setFillColor(sf::Color(255, 187, 0));
    cartDraw.setTexture(&cartTexture);

    b2Vec2 positionL = bike->wheelL->GetPosition();//new position of the body
    float32 angleL = bike->wheelL->GetAngle();
    b2Vec2 speedL = bike->wheelL->GetLinearVelocity();

    b2Vec2 positionR = bike->wheelR->GetPosition();//new position of the body
    float32 angleR = bike->wheelR->GetAngle();
    b2Vec2 speedR = bike->wheelR->GetLinearVelocity();


    wheelLDraw.setPosition(positionL.x * SCALE, positionL.y * SCALE);
    wheelRDraw.setPosition(positionR.x * SCALE, positionR.y * SCALE);
    cartDraw.setPosition(bike->cart->GetPosition().x * SCALE, (bike->cart->GetPosition().y - cartY) * SCALE);

    float speed = wheelJointL->GetMotorSpeed();
    //std::cout << speed << std::endl;

    //wheelJointL->SetMotorSpeed(speed*0.9);
    //wheelJointR->SetMotorSpeed(speed*0.9);

    float origin = WHEEL_SIZE * SCALE;

    wheelLDraw.setOrigin(origin, origin);
    wheelRDraw.setOrigin(origin, origin);
    cartDraw.setOrigin(cartX * SCALE, cartY * SCALE);


    //Draw rotations
    wheelLDraw.rotate(degToGrad(angleL));
    wheelRDraw.rotate(degToGrad(angleR));
    cartDraw.rotate(degToGrad(bike->cart->GetAngle()));



    window->draw(cartDraw);
    window->draw(wheelLDraw);
    window->draw(wheelRDraw);
}


//degrees to gradients conversion
float GameEngine::degToGrad(float deg) {
    return deg*(180/M_PI);
}