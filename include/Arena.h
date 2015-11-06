// -----------------------------------------------------
//                      .-.         /\                  |
//                       \ \       /--\ ._  _  ._   _.  |
//                        \ \     /    \|  (/_ | | (_|  |
//                        | |                           |
//                        | |     The Arena class is    |
//      /\---/\   _,---._ | |     essentially a block   |
//     /^   ^  \,'       `. ;     or tile manager for   |
//    ( O   O   )           ;     the Block class, It   |
//     `.=o=__,'            \     draws the blocks,     |
//       /         _,--.__   \    checks them for       |
//      /  _ )   ,'   `-. `-. \   collisions and        |
//     / ,' /  ,'        \ \ \ \  manages the states    |
//    / /  / ,'          (,_)(,_) that the blocks are   |
//   (,;  (,,)                jr  in during the game.   |
// -----------------------------------------------------

#ifndef ARENA_H
#define ARENA_H

#include "Sprites.h"
#include "Block.h"
#include <vector>

class Arena{

    public:

        //constructor
        Arena(sf::RenderWindow &_window);

        //destructor is important for clean shut down
        ~Arena();

        //Arena class manages a block handler in the form of a vector, this is
        //to create a map of blocks the players can or cannot destroy with bombs
        std::vector <Block* > handler;

        //reference object of RenderWindow for draw function
        sf::RenderWindow &win;

        void makeArena(int , int, int , int);

        void drawBlocks();

    private:
};


#endif // ARENA_H
