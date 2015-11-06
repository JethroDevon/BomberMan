// ------------------------------
//     __##    _                 |
//    /.__.\  | )                |
//    \ \/ /  |<   _  .___  |_   |
// #__/  . \  |_) (_) | | | |_)  |
//  \-)   . )                    |
//   \___._/  The Bomb class     |
// ____|_|____creates Bomb       |
//     " "    objects managed by |
// the PLayer class its derived  |
// from the sprites class and    |
// contains a little logic for   |
// drawing a burning fuse and    |
// explosion graphic, drawing    |
// blast animations and logic    |
// for managing collisions and   |
// bomb states relating to power |
// ups, functions will be passed |
// to bomb class by game and     |
// PLayer classes.               |
// ------------------------------
#ifndef BOMB_H
#define BOMB_H

#include "Sprites.h"

class Bomb: public Sprites{
    public:
        Bomb(int, int, int, int);
        ~Bomb();

        void setPosX(int);
        void setPosY(int);
        int getPosX();
        int getPosY();

        int getTicks();
        int getFlame();

        //sets timer on newbombs
        void setTicks(int _T);

        //sets flame size on new bombs
        void setFlame(int _F);

        //returns sprite containing frame of bomb texture
        sf::Sprite bombFrame();

        //sets the sprites position when it is created
        void setSpritePos();
    private:

        int boX, boY, boH, boW, ticks, flame;
};

#endif // BOMB_H
