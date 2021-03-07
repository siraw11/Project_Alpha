#include "gtest/gtest.h"
#include "../Hero.h"
#include "../Collision.h"
#include "../Archer.h"
#include "../Item.h"

    TEST(Hero,takeDamage){
    Hero *hero = new Archer (10,1,30,1,1,1);
    hero->takeDamage(5);
    ASSERT_EQ(hero->getLife(),5);

}

    TEST(Archer,genericItem){
    Hero *hero = new Archer (10, 1, 30, 20, 0, 0);
    hero->playerType = PlayerType::ARCHER;
    Item item(0,0,1,0,0,0);
    std::vector<Tile> *tile_vector;
    item.use(hero,tile_vector);
    ASSERT_EQ(hero->getArrow(),30);
}

    TEST(Knight,genericItem){
    Hero *hero = new Archer (10,1,30,1,20,1);
    hero->playerType = PlayerType::KNIGHT;
    Item item(0,0,1,0,0,0);
    std::vector<Tile> *tile_vector;
    item.use(hero,tile_vector);
    ASSERT_EQ(hero->getArmor(),23);
}

TEST(Mage,genericItem){
    Hero *hero = new Archer (10,1,30,1,20,10);
    hero->playerType = PlayerType::MAGE;
    Item item(0,0,1,0,0,0);
    std::vector<Tile> *tile_vector;
    item.use(hero,tile_vector);
    ASSERT_EQ(hero->getMana(),20);
}


