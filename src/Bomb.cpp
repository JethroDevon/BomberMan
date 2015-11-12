#include "Bomb.h"

Bomb::Bomb(int _X, int _Y, int _F, int _T): Sprites("Blast.png",3 , 5){

    //set fuse animation loop
    loopMode(true, 10 ,15);

    //initialises the objects member variables
    setPosX(_X);
    setPosY(_Y);
    setPos(getPosX(), getPosY());
    setTicks(_T);
    setFlame(_F);
}

//destructor is important for destroying old bomb objects after they have detonated!
Bomb::~Bomb(){

    delete this;
}


//returns amount of time until bomb detonates
int Bomb::getTicks(){

    return ticks;
}

//returns length of blast
int Bomb::getFlame(){

    return flame;
}

//sets timer on newbombs
void Bomb::setTicks(int _T){

    ticks = _T;
}

//sets flame size on new bombs
void Bomb::setFlame(int _F){

    flame = _F;
}

//draws the bomb frame from the bomb sprites array
sf::Sprite Bomb::bombFrame(){

    //the array Frames has a bomb image stored at index 5
    return getNext();
}

