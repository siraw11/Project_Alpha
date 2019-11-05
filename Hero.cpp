//
// Created by waris on 20/06/19.
//

#include "Hero.h"


Hero::Hero(int hp, int s, int sp):GameCharacter(hp,s,sp)/*,item(nullptr)*/{



}
/*Item *Hero::getItem() const {
    return item;
}

void Hero::setItem(Item *item) {
    Hero::item = item;
}*/

void Hero::heroMovement(int *level) {
    int x, y;
    const int SCALE = 3;

    if (direction == 1) {
        // up movement
        x = (int) (getPosition().x) / 32 / SCALE;
        y = (int) ((getPosition().y - 1) / 32 / SCALE);

        if (level[120 * y + x] == 0) {
            move(0, -getSpeed());
        } else {//wall up problem fix
            float offset = 0;
            while (true) {
                offset += 0.01;
                y = static_cast<int>((getPosition().y + offset) / 32 / SCALE);
                if (level[120 * y + x] == 0) {
                    move(0, offset);
                    break;
                }
            }
        }
    } else if (direction == 2) {
        //down movement
        x = (int) (getPosition().x) / 32 / SCALE;
        y = (int) ((getPosition().y) / 32 / SCALE) + 1;
        if (level[120 * y + x] == 0) {
            move(0, getSpeed());
        } else {
            //wall down problem fix
            float offset = 0;
            while (true) {
                offset += 0.01;
                y = static_cast<int>((getPosition().y - offset) / 32 / SCALE);
                if (level[120 * y + x] == 0) {
                    move(0, -offset);
                    break;
                }
            }
        }
    }else if(direction==3){
        // left movement
        x = (int) ((getPosition().x - 1) / 32 / SCALE);
        y = (int) (getPosition().y) / 32 / SCALE;
        if (level[120 * y + x] == 0) {
            move(-getSpeed(), 0);
        } else {
            //wall left problem fix
            float offset = 0;
            while (true) {
                offset += 0.01;
                x = static_cast<int>((getPosition().x + offset) / 32 /SCALE);
                if (level[120 * y + x] == 0) {
                    move(offset, 0);
                    break;
                }
            }
        }
    }else if(direction==4){
        //right movement
        x = (int) ((getPosition().x) / 32 / SCALE) + 1;
        y = (int) (getPosition().y) / 32 / SCALE;
        if (level[120 * y + x] == 0) {

            move(getSpeed(), 0);
        } else {
            //wall right problem fix
            float offset = 0;
            while (true) {
                offset += 0.01;
                x = static_cast<int>((getPosition().x - offset) / 32 /SCALE);
                if (level[120 * y + x] == 0) {
                    move(-offset, 0);
                    break;
                }
            }
        }
    }
}
