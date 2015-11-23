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

        //this is for a standard bomb when it has been placed to when it has been destroyed
        Bomb(int, int, int, int);

        //this constructor is for blast, these are for the blast that travels  up down left and right of where it had detonated
        //these are to be created and destroyed and to kill the player on contact
        Bomb();

        ~Bomb();

        //getters for returning ticks time and flame size
        double getBombTicks();
        double getFlame();

        //sets timer on newbombs
        void setBombTicks(double _T);

        //sets flame size on new bombs
        void setFlame(double _F);

        //returns sprite containing frame of bomb texture
        sf::Sprite bombFrame();

        //sets the sprites position when it is created
        void setSpritePos();

        //setter and getter for bomb if it has been used
        void setUsed(bool u);
        bool getUsed();

        //setter and getter for bomb ignition flag
        void setIgnite(bool i);
        bool getIgnite();

        //get if blast or not
        bool getBlast();
        void setBlast(bool i);

    private:

        //ticks is the original bombs timer flame is for how many blastlets to create after bomb has detonated
        double bombTicks, flame;

        //this is for if the bomb is a bomb or a blast second is if the bombs living time
        //is over and has to be removed from the array after it has gone off, ignition is the
        //state
        bool isBlast, isUsed, ignition;
};

#endif // BOMB_H
