//
// Created by Magna on 2019-06-07.
//

#ifndef MOTOCROSS2D_CHECKPOINT_H
#define MOTOCROSS2D_CHECKPOINT_H


#include "Item.h"

class Checkpoint: public Item {
private:
    bool isEnd;

public:
    explicit Checkpoint(double posX = 0, double posY = 0, double width = 0,
                        double height = 0, bool isEnd = false, std::string texture = "../textures/checkpoint.png");

    ~Checkpoint();


    void doSpecial() override final;
};


#endif //MOTOCROSS2D_CHECKPOINT_H
