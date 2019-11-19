//
// Created by Luca Graziotti on 2019-06-19.
//

#include <SFML/Graphics.hpp>
#include <GameStates/MenuPauseState.h>
#include <GameStates/GameLostState.h>
#include "Box2D/Box2D.h"

#include "GameEngine.h"
#include "Player.h"
#include "Bike.h"
#include "Item.h"
#include "Game.h"


float cartX = 0.8;
float cartY = 0.4;
sf::Texture wheelTexture;
sf::Texture cartTexture;
sf::Texture interfaceCoinTexture;
float flipAngle = 0;
int countFlips = 0;


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


    Bike bike1("", "", 5, 0, 0, true, nullptr, nullptr, nullptr);


    this->bike = bike1;

    initBike();//inizializzo la fisica del gioco
}

void GameEngine::respawn() {
    float checkpointX = Game::gameData->match->getLastCheckpoint().posX;
    float checkpointY = Game::gameData->match->getLastCheckpoint().posY + LINE - 1;
    this->bike.wheelL->SetTransform(b2Vec2(checkpointX, checkpointY), 0);
    this->bike.wheelR->SetTransform(b2Vec2(checkpointX + 1, checkpointY), 0);
    this->bike.cart->SetTransform(b2Vec2(checkpointX, checkpointY + 1), 0);
    this->bike.wheelL->SetLinearVelocity(b2Vec2(0, 0));
    this->bike.wheelR->SetLinearVelocity(b2Vec2(0, 0));
    this->wheelEngineL->SetMotorSpeed(0);
    this->wheelEngineR->SetMotorSpeed(0);
    this->run();
}


void GameEngine::run() {
    float offsetX = 3.f;
    float offsetY = 1.f;
    sf::Event event{};

    Game::gameData->match->timer->start();
    while (!this->pause) {
        Game::gameData->window.clear(sf::Color(160, 200, 244));//ripulisco nuovo frame
        this->world.Step(timeStep, velocityIterations, positionIterations);

        //la camera inizia il movimento una volta superata la metà schermo
        if (((this->bike.wheelL->GetPosition().x + offsetX) * SCALE) > (Game::gameData->window.getSize().x / 2.)) {
            //camera segue il veicolo
            double viewX = (bike.wheelL->GetPosition().x + offsetX) * SCALE;
            double viewY = (bike.wheelL->GetPosition().y - offsetY) * SCALE;
            view.setCenter((float) viewX, (float) viewY);
            Game::gameData->window.setView(view);
        }

        wheelEngineL->EnableMotor(false);//impedisce il blocco delle ruote
        wheelEngineR->EnableMotor(false);//impedisce il blocco delle ruote

        float speed = wheelEngineL->GetMotorSpeed();//Calcolo l'attuale velocità del motore


        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            //Accellerazione a Destra
            wheelEngineL->EnableMotor(true);
            wheelEngineR->EnableMotor(true);
            if (speed < 0) {
                speed = 0;
            }
            wheelEngineL->SetMotorSpeed(speed + bike.getSpeed());
            wheelEngineR->SetMotorSpeed(speed + bike.getSpeed());
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            //Accellerazione a Sinistra
            wheelEngineL->EnableMotor(true);
            wheelEngineR->EnableMotor(true);
            if (speed > 0) {
                speed = 0;
            }
            wheelEngineL->SetMotorSpeed(-(abs(speed) + bike.getSpeed()));
            wheelEngineR->SetMotorSpeed(-(abs(speed) + bike.getSpeed()));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
            //Freno a mano
            wheelEngineL->EnableMotor(true);
            wheelEngineR->EnableMotor(true);
            wheelEngineL->SetMotorSpeed(0);
            wheelEngineR->SetMotorSpeed(0);
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            std::cout << "Called Pause State" << std::endl;
            this->setPause(true);
            Game::gameData->machine.push_state(StateRef(new MenuPauseState()));
        }


        while (Game::gameData->window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                Game::gameData->window.close();
        }


        this->drawMap();//disegno la mappa del livello

        //itero la lista degli Items nella mappa

        std::list<Item *> items = Game::gameData->match->map->getMapItems();
        for (auto &item : items) {
            if (!item->isTaken()) {
                //controllo se collidono
                bool collided = checkCollision(bike.cart->GetPosition().x, bike.cart->GetPosition().y, cartX,
                                               (float) item->getPosX(), LINE + (float) item->getPosY(),
                                               (float) item->getWidth(),
                                               (float) item->getHeight());
                if (collided) {
                    item->doSpecial();//eseguo la special
                } else {
                    drawItem(item);//altrimenti disegno l'item
                }
            }
        }


        drawBike();//disegno la moto

        drawInterface();

        flipAngle = abs(degToGrad(bike.cart->GetAngle())) - (360.f * (float) countFlips);
        if (flipAngle > 350 && flipAngle < 370) {
            countFlips++;
            flipAngle = 0;
            std::cout << countFlips << " Flip!" << std::endl;
        }

        if (flipAngle > 160 && flipAngle < 220 && bike.cart->GetLinearVelocity().x <= 0 &&
            bike.cart->GetLinearVelocity().y <= 0) {
            if (Game::gameData->match->getLifes() > 0) {
                this->setPause(true);
                Game::gameData->machine.push_state(StateRef(new GameLostState()));
            } else {
            }
        }

        Game::gameData->window.display();
    }
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

bool
GameEngine::checkCollision(float r1x, float r1y, float r1w, float r2x, float r2y, float r2w, float r2h) {
    return (r1x + r1w >= r2x && r1x <= r2x + r2w) &&
           ((r1y < r2y && r2y + r2h > r1y));
}


void GameEngine::drawMap() {
    b2BodyDef groundBodyDef;
    groundBodyDef.type = b2_staticBody;
    groundBodyDef.position.Set(0, LINE);

    b2Body *groundBody = this->world.CreateBody(&groundBodyDef);
    //sf::VertexArray terrain;
    sf::VertexArray terrain(sf::TriangleStrip, Game::gameData->match->map->getMapPoints().size() * 2);


    int i = 0;
    int j = 0;
    b2Vec2 vs[Game::gameData->match->map->getMapPoints().size()];//box2D map points
    for (Position point : Game::gameData->match->map->getMapPoints()) {
        vs[i].Set(point.posX, -point.posY);
        terrain[j].position = sf::Vector2f(point.posX * SCALE,
                                           Game::gameData->window.getSize().y / 1.3 - (point.posY * SCALE));
        terrain[j].color = sf::Color(168, 75, 0);
        j++;
        terrain[j].position = sf::Vector2f(point.posX * SCALE, 4000);
        terrain[j].color = sf::Color(168, 75, 0);
        //normal index increment
        j++;
        i++;
    }
    //Unisco tutti i punti con delle rette
    b2ChainShape chain;
    chain.CreateChain(vs, Game::gameData->match->map->getMapPoints().size());


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
    bike.cart = world.CreateBody(&cartBodyDef);
    bike.cart->CreateFixture(&cartFixtureDef);


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
    bike.wheelL = world.CreateBody(&wheelDef);
    bike.wheelL->CreateFixture(&wheelFixtureDef);

    //Inizializzazione ruota destra
    wheelDef.position.Set(3, LINE - WHEEL_SIZE);//Posizione iniziale ruota destra
    bike.wheelR = world.CreateBody(&wheelDef);
    bike.wheelR->CreateFixture(&wheelFixtureDef);


    /*
     * Definizione Joints Moto
     */

    //Distance joint per connettere la ruota destra e quella sinistra
    b2DistanceJointDef dJointDefR_L;
    dJointDefR_L.Initialize(bike.wheelL, bike.wheelR, b2Vec2(0, 0), b2Vec2(0, 0));
    dJointDefR_L.collideConnected = false;
    dJointDefR_L.localAnchorA.Set(0, 0);
    dJointDefR_L.localAnchorB.Set(0, 0);
    dJointDefR_L.length = 1.1;
    world.CreateJoint(&dJointDefR_L);



    //Definizione Caratteristiche Wheel Joint
    b2WheelJointDef wheelJointDef;
    wheelJointDef.bodyA = bike.cart;
    wheelJointDef.localAnchorB.Set(0, 0);
    wheelJointDef.enableMotor = true;
    wheelJointDef.maxMotorTorque = 30;
    wheelJointDef.motorSpeed = 0;
    wheelJointDef.dampingRatio = .8;

    //Inizializzazione Wheel Joint ruota sinistra
    wheelJointDef.bodyB = bike.wheelL;
    wheelJointDef.localAnchorA.Set(-125 * 1 / SCALE, 50 * 1 / SCALE);
    wheelEngineL = (b2WheelJoint *) world.CreateJoint(&wheelJointDef);


    //Inizializzazione Wheel Joint ruota destra
    wheelJointDef.bodyB = bike.wheelR;
    wheelJointDef.enableMotor = false; //se attivo impedirebbe il movimento
    wheelJointDef.localAnchorA.Set(125 * 1 / SCALE, 50 * 1 / SCALE);
    wheelEngineR = (b2WheelJoint *) world.CreateJoint(&wheelJointDef);


    //Caricamento Texture Ruote moto
    bool wheelTextureFound = wheelTexture.loadFromFile("./textures/wheel.png");
    if (!wheelTextureFound)
        std::cout << "Impossibile caricare texture Ruote - Moto" << std::endl;
    //-----------------------

    //Caricamento Texture Cart moto
    bool cartTextureFound = cartTexture.loadFromFile("./textures/cart.png");
    if (!cartTextureFound)
        std::cout << "Impossibile caricare texture Cart - Moto" << std::endl;

    //------------------------

    bool interfaceCoinTextureFound = interfaceCoinTexture.loadFromFile("./textures/coin.png");
    if (!interfaceCoinTextureFound)
        std::cout << "Impossibile caricare texture Contatore Monete" << std::endl;

}

void GameEngine::drawBike() {
    //Disegno ruota sinistra con Texture
    sf::CircleShape wheelLDraw(WHEEL_SIZE * SCALE);
    wheelLDraw.setFillColor(sf::Color(255, 255, 255));
    wheelLDraw.setTexture(&wheelTexture);


    //Disegno ruota destra con Texture
    sf::CircleShape wheelRDraw(WHEEL_SIZE * SCALE);
    wheelRDraw.setFillColor(sf::Color(255, 255, 255));
    wheelRDraw.setTexture(&wheelTexture);

    //Disegno cart con Texture
    sf::RectangleShape cartDraw(sf::Vector2f(cartX * 2 * SCALE, cartY * 3 * SCALE));
    cartDraw.setFillColor(sf::Color(255, 255, 255));
    cartDraw.setTexture(&cartTexture);


    //Ricavo nuovi dati fisici ruota sinistra
    b2Vec2 positionWheelL = bike.wheelL->GetPosition();                //posizione
    float32 angleWheelL = ceil(degToGrad(bike.wheelL->GetAngle()));    //angolo

    //Ricavo nuovi dati fisici ruota destra
    b2Vec2 positionWheelR = bike.wheelR->GetPosition();                //posizione
    float32 angleWheelR = ceil(degToGrad(bike.wheelR->GetAngle()));    //angolo


    //Ricavo nuovi dati fisici cart
    b2Vec2 positionCart = bike.cart->GetPosition();                    //posizione
    float32 angleCart = ceil(degToGrad(bike.cart->GetAngle()));        //angolo



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



    //FIXME:Fixare la posizione del cart in caso di ribaltamento, questa soluzione attuale non è ottimale
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

    sf::Texture itemTexture;
    //Caricamento Texture Cart moto
    if (!item->getTexture().empty()) {
        bool itemTextureFound = itemTexture.loadFromFile(item->getTexture());
        if (!itemTextureFound)
            std::cout << "Impossibile caricare texture Item" << std::endl;
        else
            rect.setTexture(&itemTexture);


    }
    Game::gameData->window.draw(rect);
}

void GameEngine::drawInterface() {
    sf::Font font;
    if (!font.loadFromFile("./fonts/Arial.ttf")) {}
    float interfaceX = (view.getCenter().x) - ((view.getSize().x) / 2);
    float interfaceY = (view.getCenter().y) - ((view.getSize().y) / 2);

    sf::Sprite spriteCoin(interfaceCoinTexture);
    spriteCoin.setPosition(interfaceX, interfaceY);
    spriteCoin.setScale(0.20, 0.20);

    sf::Text textCoin;
    textCoin.setPosition(interfaceX + 150, interfaceY);
    textCoin.setFont(font);
    textCoin.setCharacterSize(80);
    textCoin.setColor(sf::Color::Black);
    textCoin.setString(std::to_string(Game::gameData->match->getMoney()));


    sf::Text textTimer;
    textTimer.setPosition(interfaceX + Game::gameData->window.getSize().x / 2 - 150, interfaceY);
    textTimer.setFont(font);
    textTimer.setCharacterSize(80);
    textTimer.setColor(sf::Color::Black);
    textTimer.setString(
            Game::gameData->match->timer->elapsedString(Game::gameData->match->timer->getTime()));

    Game::gameData->window.draw(spriteCoin);
    Game::gameData->window.draw(textCoin);
    Game::gameData->window.draw(textTimer);
}

//Conversione Radianti -> Gradi
float GameEngine::degToGrad(float deg) {
    return deg * (float) (180 / M_PI);
}
