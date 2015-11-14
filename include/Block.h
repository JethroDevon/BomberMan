
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

        Block(int ,int , int , int , int );

        //sets the position of the block
        void setBlock(int _x, int _y);

        //sets if the block is destructible or not (true for destructible)
        void setType(bool);

        bool getType();

        sf::Sprite returnBlock(bool);

    private:

        //if block is destructible then false else true, this will apply to destroying the block and drawring the block
        bool destruct;


};

#endif // BLOCK_H
