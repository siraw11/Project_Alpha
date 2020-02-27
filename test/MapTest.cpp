//
// Created by Magna on 2019-06-06.
//

#include "gtest/gtest.h"
#include "../Map.h"

TEST(Map, DefaultConstructor) {
    Map m;
    ASSERT_EQ(0, m.getRecord());
    ASSERT_EQ(false, m.getIsCompleted());
    ASSERT_EQ(false, m.getIsUnlocked());
    ASSERT_NE("", m.getId());
    ASSERT_NE("", m.getName());
    ASSERT_EQ(0, m.getMapItems().size());
}
