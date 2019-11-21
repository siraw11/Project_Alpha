//
// Created by Magna on 2019-06-03.
//
#include "gtest/gtest.h"
#include "Bike.h"

class BikeFixture : public ::testing::Test {
protected:
    Bike b;
    virtual void SetUp() {
        b.setIsUnlocked(true);
        b.setId("b1");
        b.setName("Bike");
        b.setTexture("");
        b.setPrice(300);
        b.setSpeed(100);
    }
};
