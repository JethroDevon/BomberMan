#include "Block.h"

Block::Block(bool _t, int _x, int _y, int _w, int _h): destruct(_t), pX(_x), pY(_y), bW(_w), bH(_h), Sprites("blocks.png", 1, 2){

    setSpritePos();
}

int Block::getPosX(){

    return pX;
}

int Block::getPosY(){

    return pY;
}

bool Block::getType(){

    return destruct;
}

sf::Sprite Block::returnBlock(bool _b){

    return frames[_b];
}

void Block::setPosX(int _x){

    pX = _x;
}

void Block::setPosY(int _y){

    pY = _y;
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


