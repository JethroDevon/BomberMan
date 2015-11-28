#include "Bomb.h"

Bomb::Bomb(int _X, int _Y, int _F, int _T): Sprites("Balst.png",3 , 5){

    //set fuse animation loop
    loopMode(true, 10 ,15);

    //initialises the objects member variables
    setPosX(_X);
    setPosY(_Y);
    setPos(getPosX(), getPosY());
    setBombTicks(_T);
    setFlame(_F);
    setWH(20 ,20);

    //not used yet
    setUsed(false);

    //not igniting
    setIgnite(false);

    //is a bomb not a blast
    setBlast(false);
}


Bomb::Bomb(int _X, int _Y): Sprites("Balst.png",3 , 5){

    //set fuse animation loop
    loopMode(true, 0 ,5);

     setWH(20 ,20);

    //this is a blastlet
    setBlast(true);

    //initialises the objects member variables
    setPosX(_X);
    setPosY(_Y);
    setPos(getPosX(), getPosY());
}

//destructor is important for destroying old bomb objects after they have detonated!
Bomb::~Bomb(){

    delete this;
}

void Bomb::setUsed(bool u){

    isUsed = u;
}

bool Bomb::getBlast(){

    return isBlast;
}

void Bomb::setBlast(bool i){

    isBlast = i;
}

bool Bomb::getIgnite(){

    return ignition;
}

void Bomb::setIgnite(bool i){

    ignition = i;
}

bool Bomb::getUsed(){

    return isUsed;
}


double Bomb::getBombTicks(){

    return bombTicks;
}

//returns length of blast
double Bomb::getFlame(){

    return flame;
}

//sets timer on newbombs
void Bomb::setBombTicks(double _T){

    bombTicks = _T;
}

//sets flame size on new bombs
void Bomb::setFlame(double _F){

    flame = _F;
}

//draws the bomb animation frames from the bomb sprites array based on the bombs state (alive, ignition, dead, blast)
sf::Sprite Bomb::bombFrame(){

    //if last frame of animation set bomb ignite to true
    if(frame == 14){

        setIgnite(true);
        loopMode( 6, 10);
    }

    //once at final blast frame set used to true so bomb can be marked for removal from the bomb list by another function
    //once an isBlast is false && ignition and used is true then the function to create a set amount of blastlets is called in the player function
    //these will be handled differently, this is also the case for a blastlet
    if(frame == 9){

        setUsed(true);
    }

    if(frame < 5){

        setUsed(true);
    }

    //if the last frame in bomb fuse animation is not rolling then play the bomb fuse anim
    if(!getIgnite() && !getBlast()){

        //animates the first 5 frames of bomb to iterate over 1 fifth of each set amount
        //of time it takes before bomb detonation, last frame is miscounted because I think its ugly
        if(getTicks(getBombTicks()/4)){

        //the array Frames has a bomb image stored at index 10 to 15 this will get the next frame
        return getNext();

        //else return the normal static frame, this function cannot fail to return a
        //sprite to the function that called it else the program will crash
        ///TO-DO: add try catch statement to avoid system crash if fail to return sprite
        }else{

            //returns present frame and not next frame
            return showFrame();
        }


    //now that the bomb frame anim is over the bomb has detonated, play the blast animation, set the bomb type to deadly and
    //call used after the animation is over, ignition set to true is the trigger for the create blast event in player, this too will
    // be on the bomb array however, so all players can either be killed or collide with bombs when all bomb collisions are checked against every
    //future player
    }else{

        return getNext();
    }
}


