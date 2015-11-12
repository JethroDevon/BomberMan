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

            if(w == 0 || h == 0 ) {

                handler.push_back(new Block(false ,w*25 , h*25, block_width, block_height));
            }
        }
    }

    //debug; single block for basic experementation
    //handler.push_back(new Block(false ,150 , 100, block_width, block_height));

}

//this function draws all the blocks on the screen
void Arena::drawBlocks(){

    for(auto f: handler){

        win.draw( f->returnBlock(f->getType()));
    }
}
