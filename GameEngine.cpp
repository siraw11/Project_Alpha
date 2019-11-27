//
// Created by Luca Graziotti on 2019-06-19.
//

#include <SFML/Graphics.hpp>
#include <GameStates/MenuPauseState.h>
#include <GameStates/GameLostState.h>
#include <ResourceManager/ResourceTexture.h>
#include <ResourceManager/ResourceFont.h>
#include "Box2D/Box2D.h"

#include "GameEngine.h"
#include "Player.h"
#include "Item.h"
#include "Game.h"


float cartX = 0.8;
float cartY = 0.4;
float flipAngle = 0;
int countFlips = 0;

b2Body *wheelL = nullptr;
b2Body *wheelR = nullptr;
b2Body *cart = nullptr;


GameEngine::GameEngine(b2Vec2 _gravity, int _framerate) : gravity(_gravity),
                                                          framerate(_framerate) {
    this->LINE = Game::gameData->window.getSize().y / this->SCALE / 1.3 + 0.01;
    this->timeStep = 1.0f / 60.0f;
    this->velocityIterations = 3;
    this->positionIterations = 6;

    this->view.reset(sf::FloatRect(0, 0, Game::gameData->window.getSize().x, Game::gameData->window.getSize().y));
    Game::gameData->window.setView(this->view);
    Game::gameData->window.setFramerateLimit(this->framerate);
    Game::gameData->window.clear(sf::Color(0, 0, 0));


    initBike();//inizializzo la fisica del gioco
}

void GameEngine::respawn() {
    float checkpointX = Game::gameData->match->getLastCheckpoint().posX;
    float checkpointY = Game::gameData->match->getLastCheckpoint().posY + LINE - 1;
    wheelL->SetTransform(b2Vec2(checkpointX, checkpointY), 0);
    wheelR->SetTransform(b2Vec2(checkpointX + 1, checkpointY), 0);
    cart->SetTransform(b2Vec2(checkpointX, checkpointY + 1), 0);
    wheelL->SetLinearVelocity(b2Vec2(0, 0));
    wheelR->SetLinearVelocity(b2Vec2(0, 0));
    this->wheelEngineL->SetMotorSpeed(0);
    this->wheelEngineR->SetMotorSpeed(0);
}

void GameEngine::step() {
    this->world.Step(timeStep, velocityIterations, positionIterations);
}

void GameEngine::run() {
    float offsetX = 3.f;
    float offsetY = 1.f;
    sf::Event event{};

    Game::gameData->match->getTimer()->start();
    while (!this->pause) {
        this->step();
        //la camera inizia il movimento una volta superata la metà schermo
        if (((wheelL->GetPosition().x + offsetX) * SCALE) >
            (Game::gameData->window.getSize().x / 2.)) {
            //camera segue il veicolo
            double viewX = (wheelL->GetPosition().x + offsetX) * SCALE;
            double viewY = (wheelL->GetPosition().y - offsetY) * SCALE;
            view.setCenter((float) viewX, (float) viewY);
            Game::gameData->window.setView(view);
        }

        wheelEngineL->EnableMotor(false);//impedisce il blocco delle ruote
        wheelEngineR->EnableMotor(false);//impedisce il blocco delle ruote



        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            //Accellerazione a Destra
            bikeAccellerate();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            //Accellerazione a Sinistra
            bikeDecelerate();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            //Freno a mano
            bikeBreak();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            std::cout << "Called Pause State" << std::endl;
            this->setPause(true);
            Game::gameData->machine.push_state(StateRef(new MenuPauseState()));
        }


        while (Game::gameData->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                Game::gameData->window.close();
        }

        this->checkCollisions();

        flipAngle = abs(degToGrad(cart->GetAngle())) - (360.f * (float) countFlips);
        if (flipAngle > 350 && flipAngle < 370) {
            countFlips++;
            flipAngle = 0;
            std::cout << countFlips << " Flip!" << std::endl;
        }

        this->wheelEngineL->SetMaxMotorTorque(Game::gameData->match->getBike()->getSpeed());//reset max speed
        checkDeath();
        draw();

    }
}

void GameEngine::checkCollisions() {
    for (auto &item : Game::gameData->match->getMap()->getMapItems()) {
        if (!item->isTaken()) {
            //controllo se collidono
            bool collided = checkCollision(cart->GetPosition().x,
                                           LINE - cart->GetPosition().y, cartX, cartY,
                                           (float) item->getPosX(),
                                           (float) item->getPosY(),
                                           (float) item->getWidth(),
                                           (float) item->getHeight() + 0.55);

            if (collided) {
                item->doSpecial();//eseguo la special
            }
        }
    }
}

void GameEngine::draw() {
    Game::gameData->window.clear(sf::Color(160, 200, 244));//ripulisco nuovo frame
    drawMap();
    drawItems();
    drawBike();
    drawInterface();
    Game::gameData->window.display();
}

void GameEngine::drawItems() {
    for (auto &item : Game::gameData->match->getMap()->getMapItems()) {
        if (!item->isTaken())
            drawItem(item);
    }
}

bool GameEngine::checkDeath() {
    float flipAngle = abs(abs(degToGrad(cart->GetAngle())) - (360.f * (float) countFlips));
    if (flipAngle > 160 && flipAngle < 220 && (float) cart->GetLinearVelocity().x <= 0.3 &&
        (float) cart->GetLinearVelocity().y <= 0.3) {
        if (Game::gameData->match->getLifes() > 0) {
            this->setPause(true);
            Game::gameData->machine.push_state(StateRef(new GameLostState()));
        }
        return true;
    } else {
        return false;
    }
}

void GameEngine::speedChange(float increment) {
    this->wheelEngineL->SetMaxMotorTorque(100);
    this->wheelEngineL->SetMotorSpeed(this->wheelEngineL->GetMotorSpeed() * increment);
}

void GameEngine::setPause(bool p) {
    this->pause = p;
    if (p) {
        this->timeStep = 0;
        this->positionIterations = 0;
        this->velocityIterations = 0;
    } else {
        this->timeStep = 1.0f / 60.0f;
        this->velocityIterations = 3;
        this->positionIterations = 6;
    }
}

bool GameEngine::checkCollision(float cartPosX, float cartPosY, float dimCartX, float dimCartY, float itemPosX,
                                float itemPosY, float itemW, float itemH) {
    return (itemPosX < cartPosX + dimCartX &&
            itemPosX + itemW > cartPosX &&
            itemPosY < cartPosY + dimCartY &&
            itemPosY + itemH > cartPosY);
}


void GameEngine::drawMap() {
    b2BodyDef groundBodyDef;
    groundBodyDef.type = b2_staticBody;
    groundBodyDef.position.Set(0, LINE);

    b2Body *groundBody = this->world.CreateBody(&groundBodyDef);
    sf::VertexArray terrain(sf::TriangleStrip, Game::gameData->match->getMap()->getMapPoints().size() * 2);


    int i = 0;
    int j = 0;
    b2Vec2 vs[Game::gameData->match->getMap()->getMapPoints().size()];//box2D map points
    for (Position point : Game::gameData->match->getMap()->getMapPoints()) {
        vs[i].Set(point.posX, -point.posY);
        terrain[j].position = sf::Vector2f(point.posX * SCALE,
                                           Game::gameData->window.getSize().y / 1.3 - (point.posY * SCALE));
        terrain[j].color = sf::Color(168, 75, 0);
        j++;
        terrain[j].position = sf::Vector2f(point.posX * SCALE, 4000);
        terrain[j].color = sf::Color(168, 75, 0);
        j++;
        i++;
    }
    //Unisco tutti i punti con delle rette
    b2ChainShape chain;
    chain.CreateChain(vs, Game::gameData->match->getMap()->getMapPoints().size());


    groundBody->CreateFixture(&chain, 0.0f);//0.0f->massa solido


    Game::gameData->window.draw(terrain);
}


void GameEngine::initBike() {
    /*----------------------------------------
     * Definizione Cart Moto
     */
    //Definizione oggetto fisico del Cart
    b2PolygonShape cartShape;
    cartShape.SetAsBox(cartX, cartY);
    b2BodyDef cartBodyDef;
    cartBodyDef.type = b2_dynamicBody;
    cartBodyDef.position.Set(1, LINE - cartY - WHEEL_SIZE); //posizione iniziale

    //Definizione caratteristiche fisiche
    b2FixtureDef cartFixtureDef;
    cartFixtureDef.shape = &cartShape;
    cartFixtureDef.density = 2;
    cartFixtureDef.friction = 0.5;
    cartFixtureDef.restitution = 0.2;
    cartFixtureDef.filter.groupIndex = 2;

    //Inizializzazione Cart
    cart = world.CreateBody(&cartBodyDef);
    cart->CreateFixture(&cartFixtureDef);


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
    wheelFixtureDef.density = 20;
    wheelFixtureDef.friction = 5;//attrito
    wheelFixtureDef.restitution = 0.3;//rimbalzo
    wheelFixtureDef.filter.groupIndex = -1;

    //Inizializzazione ruota sinistra
    wheelDef.position.Set(1, LINE - WHEEL_SIZE);//Posizione iniziale ruota sinistra
    wheelL = world.CreateBody(&wheelDef);
    wheelL->CreateFixture(&wheelFixtureDef);

    //Inizializzazione ruota destra
    wheelDef.position.Set(3, LINE - WHEEL_SIZE);//Posizione iniziale ruota destra
    wheelR = world.CreateBody(&wheelDef);
    wheelR->CreateFixture(&wheelFixtureDef);


    /*
     * Definizione Joints Moto
     */

    //Distance joint per connettere la ruota destra e quella sinistra
    b2DistanceJointDef dJointDefR_L;
    dJointDefR_L.Initialize(wheelL, wheelR,
                            b2Vec2(0, 0), b2Vec2(0, 0));
    dJointDefR_L.collideConnected = false;
    dJointDefR_L.localAnchorA.Set(0, 0);
    dJointDefR_L.localAnchorB.Set(0, 0);
    dJointDefR_L.length = 1.1;
    world.CreateJoint(&dJointDefR_L);



    //Definizione Caratteristiche Wheel Joint
    b2WheelJointDef wheelJointDef;
    wheelJointDef.bodyA = cart;
    wheelJointDef.localAnchorB.Set(0, 0);
    wheelJointDef.enableMotor = true;
    wheelJointDef.maxMotorTorque = Game::gameData->match->getBike()->getSpeed();
    wheelJointDef.motorSpeed = 0;
    wheelJointDef.dampingRatio = .8;

    //Inizializzazione Wheel Joint ruota sinistra
    wheelJointDef.bodyB = wheelL;
    wheelJointDef.localAnchorA.Set(-125 * 1 / SCALE, 50 * 1 / SCALE);
    wheelEngineL = (b2WheelJoint *) world.CreateJoint(&wheelJointDef);


    //Inizializzazione Wheel Joint ruota destra
    wheelJointDef.bodyB = wheelR;
    wheelJointDef.enableMotor = false; //se attivo impedirebbe il movimento
    wheelJointDef.localAnchorA.Set(125 * 1 / SCALE, 50 * 1 / SCALE);
    wheelEngineR = (b2WheelJoint *) world.CreateJoint(&wheelJointDef);
}

void GameEngine::drawBike() {
    //Disegno ruota sinistra con Texture
    sf::CircleShape wheelLDraw(WHEEL_SIZE * SCALE);
    wheelLDraw.setFillColor(sf::Color::White);
    wheelLDraw.setTexture(&Game::gameData->resources.getResource<ResourceTexture *>("wheel.png")->getTexture());


    //Disegno ruota destra con Texture
    sf::CircleShape wheelRDraw(WHEEL_SIZE * SCALE);
    wheelRDraw.setFillColor(sf::Color::White);
    wheelRDraw.setTexture(&Game::gameData->resources.getResource<ResourceTexture *>("wheel.png")->getTexture());

    //Disegno cart con Texture
    sf::RectangleShape cartDraw(sf::Vector2f(cartX * 2 * SCALE, cartY * 3 * SCALE));
    cartDraw.setFillColor(sf::Color::White);
    cartDraw.setTexture(&Game::gameData->resources.getResource<ResourceTexture *>(
            Game::gameData->match->getBike()->getTexture())->getTexture());


    //Ricavo nuovi dati fisici ruota sinistra
    b2Vec2 positionWheelL = wheelL->GetPosition();                //posizione
    float32 angleWheelL = ceil(degToGrad(wheelL->GetAngle()));    //angolo

    //Ricavo nuovi dati fisici ruota destra
    b2Vec2 positionWheelR = wheelR->GetPosition();                //posizione
    float32 angleWheelR = ceil(degToGrad(wheelR->GetAngle()));    //angolo


    //Ricavo nuovi dati fisici cart
    b2Vec2 positionCart = cart->GetPosition();                    //posizione
    float32 angleCart = ceil(degToGrad(cart->GetAngle()));        //angolo



    float origin = WHEEL_SIZE * SCALE;
    wheelLDraw.setOrigin(origin, origin);
    wheelRDraw.setOrigin(origin, origin);
    cartDraw.setOrigin((cartX) * SCALE, (cartY) * SCALE);


    //Aggiorno la posizione degli oggetti disegnati
    wheelLDraw.setPosition(positionWheelL.x * SCALE, positionWheelL.y * SCALE);
    wheelRDraw.setPosition(positionWheelR.x * SCALE, positionWheelR.y * SCALE);


    //Aggiorno la rotazione degli oggetti disegnati
    wheelLDraw.rotate(angleWheelL);
    wheelRDraw.rotate(angleWheelR);
    cartDraw.rotate(angleCart);


    if (flipAngle > 90) {
        cartDraw.setPosition(positionCart.x * SCALE, (positionCart.y + cartY) * SCALE);
    } else {
        cartDraw.setPosition(positionCart.x * SCALE, (positionCart.y - cartY) * SCALE);
    }

    //Disegno gli oggetti

    Game::gameData->window.draw(cartDraw);
    Game::gameData->window.draw(wheelLDraw);
    Game::gameData->window.draw(wheelRDraw);
}

void GameEngine::drawItem(Item *item) {
    sf::RectangleShape rect;
    rect.setPosition((float) item->getPosX() * SCALE, (LINE - (float) item->getPosY()) * SCALE);
    rect.setSize(sf::Vector2f(item->getWidth() * SCALE, -item->getHeight() * SCALE));
    if (!item->getTexture().empty()) {
        rect.setTexture(&Game::gameData->resources.getResource<ResourceTexture *>(item->getTexture())->getTexture());
    }
    rect.setRotation(item->getAngle());
    Game::gameData->window.draw(rect);
}

void GameEngine::drawInterface() {
    float interfaceX = (view.getCenter().x) - ((view.getSize().x) / 2);
    float interfaceY = (view.getCenter().y) - ((view.getSize().y) / 2);

    sf::Sprite spriteCoin(Game::gameData->resources.getResource<ResourceTexture *>("coin.png")->getTexture());
    spriteCoin.setPosition(interfaceX, interfaceY);
    spriteCoin.setScale(0.20, 0.20);
    Game::gameData->window.draw(spriteCoin);

    sf::Text textCoin;
    textCoin.setPosition(interfaceX + 150, interfaceY);
    textCoin.setFont(Game::gameData->resources.getResource<ResourceFont *>("arial.ttf")->getFont());
    textCoin.setCharacterSize(80);
    textCoin.setFillColor(sf::Color::Black);
    textCoin.setString(std::to_string(Game::gameData->match->getMoney()));
    Game::gameData->window.draw(textCoin);


    sf::Sprite spriteHeart(Game::gameData->resources.getResource<ResourceTexture *>("heart.png")->getTexture());
    float heartPosX = interfaceX + 400;
    for (int i = 0; i < Game::gameData->match->getLifes(); ++i) {
        spriteHeart.setPosition(heartPosX, interfaceY);
        spriteHeart.setScale(0.20, 0.20);
        Game::gameData->window.draw(spriteHeart);
        heartPosX += 130;
    }


    sf::Text textTimer;
    textTimer.setPosition(interfaceX + Game::gameData->window.getSize().x / 2 - 150, interfaceY);
    textTimer.setFont(Game::gameData->resources.getResource<ResourceFont *>("arial.ttf")->getFont());
    textTimer.setCharacterSize(80);
    textTimer.setFillColor(sf::Color::Black);
    textTimer.setString(
            Game::gameData->match->getTimer()->elapsedString(Game::gameData->match->getTimer()->getTime()));
    Game::gameData->window.draw(textTimer);


}

//Conversione Radianti -> Gradi
float GameEngine::degToGrad(float deg) {
    return deg * (float) (180 / M_PI);
}


Position GameEngine::getBikePosition() const {
    return Position{cart->GetPosition().x, cart->GetPosition().y};
}

void GameEngine::bikeAccellerate() {
    float speed = wheelEngineL->GetMotorSpeed();
    wheelEngineL->EnableMotor(true);
    wheelEngineR->EnableMotor(true);
    if (speed < 0) {
        speed = 0;
    }
    wheelEngineL->SetMotorSpeed(speed + Game::gameData->match->getBike()->getSpeed());
    wheelEngineR->SetMotorSpeed(speed + Game::gameData->match->getBike()->getSpeed());
}

void GameEngine::bikeDecelerate() {
    float speed = wheelEngineL->GetMotorSpeed();
    wheelEngineL->EnableMotor(true);
    wheelEngineR->EnableMotor(true);
    if (speed > 0) {
        speed = 0;
    }
    wheelEngineL->SetMotorSpeed(-(abs(speed) + Game::gameData->match->getBike()->getSpeed()));
    wheelEngineR->SetMotorSpeed(-(abs(speed) + Game::gameData->match->getBike()->getSpeed()));
}

void GameEngine::bikeBreak() {
    wheelEngineL->EnableMotor(true);
    wheelEngineR->EnableMotor(true);
    wheelEngineL->SetMotorSpeed(0);
    wheelEngineR->SetMotorSpeed(0);
}


const b2Vec2 &GameEngine::getGravity() const {
    return gravity;
}

float32 GameEngine::getTimeStep() const {
    return timeStep;
}

int GameEngine::getFramerate() const {
    return framerate;
}

int32 GameEngine::getPositionIterations() const {
    return positionIterations;
}

int32 GameEngine::getVelocityIterations() const {
    return velocityIterations;
}

const b2World &GameEngine::getWorld() const {
    return world;
}

void GameEngine::setGravity(const b2Vec2 &_gravity) {
    this->gravity = _gravity;
}

void GameEngine::setVelocityIterations(int32 _velocityIterations) {
    this->velocityIterations = _velocityIterations;
}

void GameEngine::setPositionIterations(int32 _positionIterations) {
    this->positionIterations = _positionIterations;
}

void GameEngine::setTimeStep(float32 _timeStep) {
    this->timeStep = _timeStep;
}

void GameEngine::setFramerate(int _framerate) {
    this->framerate = _framerate;
}

void GameEngine::setWorld(const b2World &_world) {
    this->world = _world;
}
