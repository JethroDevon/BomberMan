//this class deals with the blocks, backgrounds and player collisions in the bomber man arena
#include "Arena.h"

Arena::Arena(sf::RenderWindow &_window): win(_window){


}

Arena::~Arena(){

    //callse destructor on each object in vector
    handler.clear();
}

//this should make the blocks in the arena
void Arena::makeArena(int arena_width, int arena_height, int block_width, int block_height){

    for(int h = 0; h < arena_width; h++){
        for(int w = 0; w < arena_height; w++){

            if(h < arena_width*arena_height) {


                handler.push_back(new Block(false ,h*50 , w*50, 50, 50));
            }
        }
    }
}

//this function draws all the blocks on the screen
void Arena::drawBlocks(){

    for(auto f: handler){

        win.draw( f->returnBlock(f->getType()));
    }
}
