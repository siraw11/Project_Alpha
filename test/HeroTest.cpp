#include "gtest/gtest.h"
#include "../Hero.h"
#include "../Collision.h"
#include "../Archer.h"


TEST(Hero,takeDamage){
    Hero *hero = new Archer (10,1,30,1,1,1);
    hero->takeDamage(5);
    ASSERT_EQ(hero->getLife(),5);
    
}











