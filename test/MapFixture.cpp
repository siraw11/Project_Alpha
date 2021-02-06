//
// Created by Luca Graziotti on 21/11/2019.
//


#include <ResourceManager/ResourceManager.h>
#include "gtest/gtest.h"
#include "Map.h"
#include "ResourceManager/LevelFactory.h"

class MapFixture : public ::testing::Test {
protected:
    Map m;

    virtual void SetUp() {
        m.setId("test");
        m.setIsUnlocked(true);
        m.setName("Livello Test");
        m.setRecord(278347);
    }
};

TEST_F(MapFixture, TestMapLoad) {
    ASSERT_EQ(0, m.getMapPoints().size());
    //il primo livello deve essere sblocatto ma non completato di default
    m = *LevelFactory::getLevel("lv1");
    ASSERT_LT(0, m.getMapPoints().size());
    ASSERT_EQ(0, m.getRecord());
    m.setRecord(5000);
    ASSERT_EQ(5000, m.getRecord());
    ASSERT_EQ(true, m.getIsUnlocked());
    ASSERT_EQ(false, m.getIsCompleted());


    //controllo che il secondo non sia sbloccato e che i punti siano aggiornati
    m = *LevelFactory::getLevel("lv2");
    ASSERT_LT(0, m.getMapPoints().size());
    ASSERT_EQ(0, m.getRecord());
    ASSERT_EQ(false, m.getIsCompleted());
    ASSERT_EQ(false, m.getIsUnlocked());
}
