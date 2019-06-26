//
// Created by Magna on 2019-06-03.
//

#include "Bike.h"

#include <SFML/Graphics.hpp>
#include "Box2D/Box2D.h"

const float WHEEL_SIZE = 0.2;


Bike::Bike(std::string _name, std::string _color, float _speed, int _usability, int _price, bool _isUnlocked,GameEngine* _engine,b2Body* _wheelL,b2Body* _wheelR) : name(
        _name), color(_color), speed(_speed), usability(_usability), price(_price), isUnlocked(_isUnlocked),engine(_engine),wheelL(_wheelL),wheelR(_wheelR) {


    b2BodyDef wheelLDef;
    wheelLDef.type = b2_dynamicBody;
    wheelLDef.position.Set(150.f, engine->window.getSize().y/1.7);//initial position

    wheelL = engine->world.CreateBody(&wheelLDef);
    b2CircleShape dynamicWheel;
    dynamicWheel.m_p.Set(0, 0);
    dynamicWheel.m_radius = WHEEL_SIZE*engine->SCALE;
    //altre caratteristiche fisiche della ruota
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicWheel;
    fixtureDef.density = 1.f;
    fixtureDef.friction = 0.3f;//attrito
    fixtureDef.restitution = 0.5f;//rimbalzo
    wheelL->CreateFixture(&fixtureDef);
    //disegno la ruota



    b2BodyDef wheelRDef;
    wheelRDef.type = b2_dynamicBody;
    wheelRDef.position.Set(300.f, engine->window.getSize().y/1.7);//initial position


    wheelR = engine->world.CreateBody(&wheelRDef);

    //creo la ruota come sfera(sempre Box2D)
    b2CircleShape dynamicWheelR;
    dynamicWheelR.m_p.Set(0, 0);
    dynamicWheelR.m_radius = WHEEL_SIZE*engine->SCALE;
    //altre caratteristiche fisiche della ruota
    b2FixtureDef fixtureDefR;
    fixtureDefR.shape = &dynamicWheelR;
    fixtureDefR.density = 1.f;
    fixtureDefR.friction = 0.3f;//attrito
    fixtureDefR.restitution = 0.5f;//rimbalzo
    wheelR->CreateFixture(&fixtureDefR);
    //disegno la ruota


    b2DistanceJointDef jointDef;
    jointDef.Initialize(wheelL, wheelR, wheelL->GetLocalCenter(), wheelL->GetLocalCenter()); jointDef.collideConnected = true;
    jointDef.bodyA = wheelL;
    jointDef.bodyB = wheelR;
    jointDef.localAnchorA.Set(2,2);
    jointDef.localAnchorB.Set(0,0);
    jointDef.length = 125;
    engine->world.CreateJoint(&jointDef);
}

const std::string &Bike::getName() const {
    return name;
}

void Bike::setName(const std::string &name) {
    Bike::name = name;
}

const std::string &Bike::getColor() const {
    return color;
}

void Bike::setColor(const std::string &color) {
    Bike::color = color;
}

float Bike::getSpeed() const {
    return speed;
}

void Bike::setSpeed(float speed) {
    Bike::speed = speed;
}


int Bike::getUsability() const {
    return usability;
}

void Bike::setUsability(int usability) {
    Bike::usability = usability;
}


int Bike::getPrice() const {
    return price;
}

void Bike::setPrice(int price) {
    Bike::price = price;
}

bool Bike::getIsUnlocked() const {
    return isUnlocked;
}

void Bike::setIsUnlocked(bool isUnlocked) {
    Bike::isUnlocked = isUnlocked;
}

void Bike::draw(sf::RenderWindow *window){
    sf::Texture texture;
    if(!texture.loadFromFile("../textures/wheel.png"))
        std::cout << "Cannot load texture"<< std::endl;
    sf::Sprite sprite;
    sprite.setTexture(texture);

    sf::CircleShape wheelLDraw(WHEEL_SIZE* engine->SCALE);
    wheelLDraw.setFillColor(sf::Color(255, 187, 0));
    wheelLDraw.setTexture(&texture);


    sf::CircleShape wheelRDraw(WHEEL_SIZE* engine->SCALE);
    wheelRDraw.setFillColor(sf::Color(255, 187, 0));
    wheelRDraw.setTexture(&texture);


    b2Vec2 positionL = wheelL->GetPosition();//new position of the body
    float32 angleL = wheelL->GetAngle();
    b2Vec2 speedL = wheelL->GetLinearVelocity();

    b2Vec2 positionR = wheelR->GetPosition();//new position of the body
    float32 angleR = wheelR->GetAngle();
    b2Vec2 speedR = wheelR->GetLinearVelocity();



    wheelLDraw.setPosition(positionL.x, positionL.y - WHEEL_SIZE* engine->SCALE/2);
    wheelRDraw.setPosition(positionR.x, positionR.y- WHEEL_SIZE* engine->SCALE/2);

    //TODO:Add wheel rotation and fix position

    window->draw(wheelLDraw);
    window->draw(wheelRDraw);


}

Bike::~Bike() {

}
