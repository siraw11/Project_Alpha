//
// Created by Luca Graziotti on 26/11/2019.
//

#include <ResourceManager/ResourceFont.h>
#include "gtest/gtest.h"
#include "ResourceManager/ResourceManager.h"


TEST(ResourceManager, DefaultConstructor) {
    ResourceManager r;
    r.add(new ResourceFont("arial.ttf", "./resources/fonts/arial.ttf"));
    ASSERT_EQ(1, r.getSize());
    r.remove("arial.ttf");
    ASSERT_EQ(0, r.getSize());
}


TEST(ResourceManager, TestException) {
    ResourceManager r;
    bool errorVerified = false;
    try {
        r.add(new ResourceFont("arial.ttf", "./resources/fonts/NotExistingFIle"));
    } catch (ResourceManagerException e) {
        errorVerified = true;
    }
    ASSERT_TRUE(errorVerified);
    ASSERT_EQ(0, r.getSize());
}