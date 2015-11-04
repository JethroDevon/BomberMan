
// ----------------------------------------------
//        ,-~~-.___              _               |
//       / |  '    \            | )              |
//      (  )        0           |<  |  _   _ |   |
//       \_/-, ,---'            |_) | (_) (_ |<  |
//          ====           //                    |
//          /  \-'~;    /~~~(O) The Block class  |
//         /  __/~|   /       | is essentially a |
//       =(  _____| (_________| wrapper for the  |
// Sprite class it derives from, it contains     |
// only two frames destructible and not          |
// destructible, a loop in the Arena class will  |
// manage dynamically generated block objects.   |
// ----------------------------------------------

#ifndef BLOCK_H
#define BLOCK_H

#include "Sprites.h"

class Block: public Sprites{

    public:

        Block(bool ,int , int , int , int );

        //sets the position of the block
        void setBlock(int _x, int _y);

        //sets if the block is destructible or not (true for destructible)
        void setType(bool);

        int getPosX();

        int getPosY();

        bool getType();

        void setPosX(int);

        void setPosY(int);

        sf::Sprite returnBlock(bool);

        //sets the sprites position
        void setSpritePos();

    private:

        //if block is destructible then false else true, this will apply to destroying the block and drawring the block
        bool destruct;

        //position x y and block width and block height
        int pX, pY, bW, bH;
};

#endif // BLOCK_H
