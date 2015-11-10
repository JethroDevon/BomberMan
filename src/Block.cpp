#include "Block.h"

Block::Block(bool _t, int _x, int _y, int _w, int _h): destruct(_t), Sprites("blocks.png", 1, 2){

    loopMode(10, 15);
    setXY(_x, _y);
    setWH( _w, _h);
}



bool Block::getType(){

    return destruct;
}

sf::Sprite Block::returnBlock(bool _b){

    return frames[_b];
}

void Block::setType(bool _b){

    destruct = _b;
}

