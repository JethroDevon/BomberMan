#include "Block.h"

Block::Block(bool _t, int _x, int _y, int _w, int _h): destruct(_t), blX(_x), blY(_y), blW(_w), blH(_h), Sprites("blocks.png", 1, 2){

    loopMode(10, 15);
    setSpritePos();
}

int Block::getPosX(){

    return blX;
}

int Block::getPosY(){

    return blY;
}

bool Block::getType(){

    return destruct;
}

sf::Sprite Block::returnBlock(bool _b){

    return frames[_b];
}

void Block::setPosX(int _x){

    blX = _x;
}

void Block::setPosY(int _y){

    blY = _y;
}

void Block::setType(bool _b){

    destruct = _b;
}

//sets the sprites position
void Block::setSpritePos(){

    for(auto &f: frames){

        f.setPosition( getPosX(), getPosY());
    }
}


